#ifdef __GNUC__
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,abm,popcnt,fma4,lzcnt,avx")
#endif
#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>
#include <array>

template<class T, int Dim>
class darray {
public:
  using element_t = typename darray<T, Dim-1>::array_t;
  using array_t = element_t*;
  template<class... Args>
  darray(Args... args) :
      //p(new element_t[dim]),
      p(),
      dims{size_t(args)...} {
    p = init(size_t(args)...);
  }

  ~darray() {
    free(p, dims.data());
  }

  const std::array<size_t, Dim>& size() { return dims;};

  template<class... Args>
  static array_t init(size_t dim, Args... args) {
    array_t p = new element_t[dim];
    for (size_t i = 0; i < dim; i++) {
      p[i] = darray<T, Dim - 1>::init(args...);
    }
    return p;
  }

  static array_t free(array_t p, size_t* dims) {
    for (size_t i = 0; i < dims[0]; i++) {
      darray<T, Dim - 1>::free(p[i], dims + 1);
    }
    delete[] p;
  }

  class ref {
    array_t p;
  public:
    ref(array_t p) :
      p(p) {}
    element_t operator[](size_t idx) {
      return p[idx];
    }
    const element_t operator[](size_t idx) const {
      return p[idx];
    }
  };

  typename darray<T, Dim - 1>::ref operator[](size_t idx) {
    return typename darray<T, Dim-1>::ref(p[idx]);
  }

  const typename darray<T, Dim - 1>::ref operator[](size_t idx) const {
    return typename darray<T, Dim-1>::ref(p[idx]);
  }

  void copy(const darray<T, Dim>& other) {
    copy(p, dims.data(), other.p);
  }

  static void copy(array_t p, size_t* dims, array_t other_p) {
    for (size_t i = 0; i < dims[0]; i++) {
      darray<T, Dim - 1>::copy(p[i], dims + 1, other_p[i]);
    }
  }
private:
  array_t p;
  std::array<size_t, Dim> dims;
};

template<class T>
class darray<T, 1> {
public:
  using element_t = T;
  using array_t = T*;

  darray(size_t dim) :
      p(),
      dims{dim} {
    p = init(dim);
  }

  ~darray() {
    free(p, dims.data());
  }

  const std::array<size_t, 1>& size() { return dims;};

  static array_t init(size_t dim) {
    return new T[dim]();
  }

  static array_t free(array_t p, size_t* /* dims */) {
    delete[] p;
  }

  using ref = array_t;

  T& operator[](size_t idx) {
    return p[idx];
  }

  const T& operator[](size_t idx) const {
    return p[idx];
  }

  void copy(const darray<T, 1>& other) {
    copy(p, dims.data(), other.p);
  }

  static void copy(array_t p, size_t* dims, array_t other_p) {
    std::copy_n(other_p, dims[0], p);
  }
private:
  array_t p;
  std::array<size_t, 1> dims;
};

void run(std::istream &in, std::ostream &out) {
  int n, t;
  in >> n >> t;
  darray<int, 4> dyn(4, 2, t + 1, t);
  darray<int, 4> dynNext(4, 2, t + 1, t);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++) {
      int previ = i - (2 * j - 1);
      if (previ >= 0 && previ < 4) {
        if (j == 0) {
          dyn[i][j][0][0] = 4 - previ;
        } else {
          dyn[i][j][0][0] = previ + 1;
        }
      }
    }
  }
  dynNext.copy(dyn);
  for (int pos = 0; pos < n-2; pos++) {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 2; j++) {
        for (int k = 0; k <= t; k++) {
          for (int l = 0; l < t; l++) {
            dynNext[i][j][k][l]=0;
          }
        }
      }
      for (int previ = 0; previ < 4; previ++) {
        if (previ == i) continue;
        int j = i > previ ? 1 : 0;
        for (int prevj = 0; prevj < 2; prevj++) {
          if (i > previ) {
            int dt2 = prevj == 0 ? 1 : 0;
            for (int k = 0; k <= t; k++) {
              for (int l = dt2; l < t; l++) {
                dynNext[i][j][k][l] += dyn[previ][prevj][k][l - dt2];
              }
            }
          } else {
            int dt = prevj == 1 ? 1 : 0;
            for (int k = dt; k <= t; k++) {
              for (int l = 0; l < t; l++) {
                dynNext[i][j][k][l] += dyn[previ][prevj][k - dt][l];
              }
            }
          }
        }
      }
    }
    dyn.copy(dynNext);
  }
  int ans = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++) {
      ans += dyn[i][j][t][t-1];
    }
  }
  out << ans << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}