#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
// #include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
// #include <cuchar>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
// #include <codecvt>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

#if __cplusplus >= 201402L
#include <shared_mutex>
#endif

#if __cplusplus >= 201703L
#include <any>
#include <charconv>
// #include <execution>
#include <filesystem>
#include <optional>
// #include <memory_resource>
#include <string_view>
#include <variant>
#endif

#if __cplusplus > 201703L
#include <barrier>
#include <bit>
#include <compare>
#include <concepts>
#if __cpp_impl_coroutine
# include <coroutine>
#endif
#include <latch>
#include <numbers>
#include <ranges>
#include <span>
#include <stop_token>
#include <semaphore>
#include <source_location>
#include <syncstream>
#include <version>
#endif

using namespace std;

using ll = long long;
using db = long double;
using str = string;
using pi = pair<int, int>;
#define mp make_pair
#define f first
#define s second

#define tcT template<class T
tcT> using V = vector<T>;
tcT, size_t SZ> using AR = array<T, SZ>;
using vi = V<int>;
using vb = V<bool>;
using vpi = V<pi>;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define sor(x) sort(all(x))
#define rsz resize
#define pb push_back
#define ft front()
#define bk back()
#define lb lower_bound

const int MOD = 1e9+7;
const ll BIG = 1e18;
const db PI = acos((db)-1);
mt19937 rng(0);

tcT> bool ckmin(T& a, const T& b){
    return b < a ? a = b, 1 : 0;
}
tcT> bool ckmax(T& a, const T& b){
    return a < b ? a = b, 1 : 0;
}

const int mx = 400005;

struct DSU{
    vi e; 
    vi height;
    void init(int N){
        e = vi(N, -1);
        height = vi(N, -1);
    }
    int get(int x){
        return e[x] < 0 ? x : e[x] = get(e[x]);
    }
    bool sameSet(int a, int b){
        return get(a) == get(b);
    }
    int size(int x){
        return -e[get(x)];
    }
    bool unite(int x, int y){
        x = get(x), y = get(y); if(x == y) return 0;
        if(e[x] > e[y]) swap(x, y);
        e[x]+=e[y]; e[y] = x; 
        return 1;
    }
};

DSU dsu;

int A[mx];
int cur_node[mx]; //for each index, corresponds to some node

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin >> N;
    dsu.init(2*mx+5);
    for(int i = 1; i <= N; i++){
        cin >> A[i];
        cur_node[i] = i;
    }

    map<int, int> height_rep;
    for(int i = 1; i <= N; i++){
        //update dsu components, height, height_rep
        if(height_rep.count(A[i])){
            dsu.unite(height_rep[A[i]], i);
        }
        height_rep[A[i]] = dsu.get(i);
        dsu.height[dsu.get(i)] = A[i];
    }

    auto moveComponentTo = [&](int h_from, int h_to, auto h_from_iterator){
        // assert(h_from != h_to);
        // assert(height_rep.count(h_from));
        int from_rep = h_from_iterator->s;

        auto h_to_iterator = height_rep.find(h_to);
        if(h_to_iterator != height_rep.end()){
            dsu.unite(h_to_iterator->s, from_rep);
            h_to_iterator->s = dsu.get(from_rep);
        }
        else{
            height_rep[h_to] = dsu.get(from_rep);
        }
        dsu.height[dsu.get(from_rep)] = h_to;
        height_rep.erase(h_from);
    };

    int Q;
    cin >> Q;
    int node_num = N;
    for(int j = 1; j <= Q; j++){
        int typ; cin >> typ;
        if(typ == 1){
            int k, w; cin >> k >> w;
            cur_node[k] = ++node_num;

            if(height_rep.count(w)){
                dsu.unite(height_rep[w], node_num);
            }
            dsu.height[dsu.get(node_num)] = w;
            height_rep[w] = dsu.get(node_num);
        }
        else if(typ == 2){
            int k; cin >> k;
            int node = cur_node[k];
            cout << dsu.height[dsu.get(node)] << "\n";
        }
        else if(typ == 3){
            int l, r; cin >> l >> r;
            int mid = (r+l)/2;
            //l <= x <= mid
            // cout << "MOVING" << "\n";
            while(true){
                auto it = height_rep.lb(l);
                if(it == height_rep.end() || it->f > mid) break;
                moveComponentTo(it->f, l-1, it);
            }

            //mid+1 <= x <= r
            while(true){
                auto it = height_rep.lb(mid+1);
                if(it == height_rep.end() || it->f > r) break;
                moveComponentTo(it->f, r+1, it);
            }
        }
    }

    // cout << "height_rep" << "\n";
    // for(auto u: height_rep){
    //     cout << u.f << " " << u.s << "\n";
    // }


}