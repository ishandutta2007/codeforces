/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Egor Kulikov
 */







#include <bits/stdc++.h>

using namespace std;

template<typename T>
class Vector : public vector<T> {
    using parent = vector<T>;
public:
    Vector() : parent() {}

    explicit Vector(size_t __n) : parent(__n) {}

    Vector(size_t __n, const T &__value) : parent(__n, __value) {}

    explicit Vector(const parent &__x) : parent(__x) {}

    Vector(const Vector &__x) : parent(__x) {}

    Vector(Vector &&__x) noexcept : parent(move(__x)) {}

    Vector(initializer_list<T> __l) : parent(__l) {}

    template<typename _InputIterator, typename = std::_RequireInputIter<_InputIterator>>
    Vector(_InputIterator __first, _InputIterator __last) : parent(__first, __last) {}

    const T &operator[](size_t ind) const {
#ifdef LOCAL
        if (ind >= parent::size()) {
            throw "Out of bounds";
        }
#endif
        return *(parent::_M_impl._M_start + ind);
    }

    T &operator[](size_t ind) {
#ifdef LOCAL
        if (ind >= parent::size()) {
            throw "Out of bounds";
        }
#endif
        return *(parent::_M_impl._M_start + ind);
    }

    Vector<T> &operator=(Vector<T> &&__x) noexcept {
        parent::operator=(__x);
        return *this;
    }

    Vector<T> &operator=(const Vector<T> &__x) {
        parent::operator=(__x);
        return *this;
    }
};

template<>
class Vector<bool> : public vector<bool> {
    using parent = vector<bool>;
public:
    Vector() : parent() {}

    explicit Vector(size_t __n) : parent(__n) {}

    Vector(size_t __n, const bool &__value) : parent(__n, __value) {}

    explicit Vector(const parent &__x) : parent(__x) {}

    Vector(const Vector &__x) : parent(__x) {}

    Vector(Vector &&__x) noexcept : parent(move(__x)) {}

    Vector(initializer_list<bool> __l) : parent(__l) {}

    template<typename _InputIterator, typename = std::_RequireInputIter<_InputIterator>>
    Vector(_InputIterator __first, _InputIterator __last) : parent(__first, __last) {}

    parent::const_reference operator[](size_t ind) const {
#ifdef LOCAL
        if (ind >= parent::size()) {
            throw "Out of bounds";
        }
#endif
        return *const_iterator(this->_M_impl._M_start._M_p
                               + ind / int(_S_word_bit), ind % int(_S_word_bit));
    }

    parent::reference operator[](size_t ind) {
#ifdef LOCAL
        if (ind >= parent::size()) {
            throw "Out of bounds";
        }
#endif
        return *iterator(this->_M_impl._M_start._M_p
                         + ind / int(_S_word_bit), ind % int(_S_word_bit));
    }

    Vector<bool> &operator=(Vector<bool> &&__x) noexcept {
        parent::operator=(__x);
        return *this;
    }

    Vector<bool> &operator=(const Vector<bool> &__x) {
        parent::operator=(__x);
        return *this;
    }
};

#ifdef LOCAL
#define vec Vector
#else
#define vec vector
#endif

using vi = vec<int>;


#define all(v) (v).begin(), (v).end()

using ll = long long;
using pii = pair<int, int>;

const double PI = atan(1) * 4;

template<typename T>
T minim(T &was, T cand) {
    return was = min(was, cand);
}

template<typename T>
T maxim(T &was, T cand) {
    return was = max(was, cand);
}


template<typename D>
D dPower(D base, ll exponent) {
    if (exponent < 0) {
        return dPower(1 / base, -exponent);
    }
    if (exponent == 0) {
        return 1;
    }
    if ((exponent & 1) == 1) {
        return dPower(base, exponent - 1) * base;
    } else {
        D res = dPower(base, exponent >> 1);
        return res * res;
    }
}


template<typename T>
class arr {
    T *b;
    T *e;
    int n;
public:
    arr() : b(nullptr), e(nullptr), n(0) {}

    arr(int n) : n(n) {
#ifdef LOCAL
        if (n < 0) {
            throw "bad alloc";
        }
#endif
        if (n > 0) {
            b = new T[n];
            e = b + n;
        } else {
            b = e = nullptr;
        }
    }

    arr(int n, const T &init) : n(n) {
#ifdef LOCAL
        if (n < 0) {
            throw "bad alloc";
        }
#endif
        if (n > 0) {
            b = new T[n];
            e = b + n;
            fill(b, e, init);
        } else {
            b = e = nullptr;
        }
    }

    arr(initializer_list<T> l) : n(l.size()) {
        if (n == 0) {
            b = e = nullptr;
        } else {
            b = new T[l.size()];
            e = b + n;
            copy(all(l), b);
        }
    }

    arr(T *b, int n) : b(b), e(b + n), n(n) {}

    arr(T *b, T *e) : b(b), e(e), n(e - b) {}

    size_t size() const {
        return n;
    }

    T *begin() {
        return b;
    }

    T *end() {
        return e;
    }

    arr<T> clone() const {
        arr<T> res(n);
        copy(b, e, res.begin());
        return res;
    }

    T &operator[](int at) {
#ifdef LOCAL
        if (at < 0 || at >= n) {
            throw "Out of bounds";
        }
#endif
        return b[at];
    }

    const T &operator[](int at) const {
#ifdef LOCAL
        if (at < 0 || at >= n) {
            throw "Out of bounds";
        }
#endif
        return b[at];
    }

    void swap(arr<T> &arr) {
        std::swap(b, arr.b);
        std::swap(e, arr.e);
        std::swap(n, arr.n);
    }
};

typedef arr<int> arri;

void decreaseByOne() {}

template<typename T, class...Vs>
void decreaseByOne(arr<T> &array, Vs &...vs) {
    int n = array.size();
    for (int i = 0; i < n; ++i) {
        array[i]--;
    }
    decreaseByOne(vs...);
}

template<typename T, typename U>
void decreaseByOne(arr<pair<T, U> > &v) {
    for (auto &p : v) {
        p.first--;
        p.second--;
    }
}


template<typename T>
class arr2d {
    T *b;
    T *e;
    int d1;
    int d2;
    int sz;

public:
    arr2d() : b(nullptr), e(nullptr), d1(0), d2(0), sz(0) {}

    arr2d(int d1, int d2) : d1(d1), d2(d2), sz(d1 * d2) {
        b = new T[sz];
        e = b + sz;
    }

    arr2d(int d1, int d2, const T &init) : d1(d1), d2(d2), sz(d1 * d2) {
        b = new T[sz];
        e = b + sz;
        fill(b, e, init);
    }

    arr2d(T *b, int d1, int d2) : b(b), e(b + d1 * d2), d1(d1), d2(d2), sz(d1 * d2) {}

    size_t size() const {
        return sz;
    }

    size_t dim1() const {
        return d1;
    }

    size_t dim2() const {
        return d2;
    }

    T *begin() {
        return b;
    }

    T *end() {
        return e;
    }

    T &operator()(int i1, int i2) {
#ifdef LOCAL
        if (i1 < 0 || i1 >= d1 || i2 < 0 || i2 >= d2) {
            throw "Out of bounds";
        }
#endif
        return b[i1 * d2 + i2];
    }

    const T &operator()(int i1, int i2) const {
#ifdef LOCAL
        if (i1 < 0 || i1 >= d1 || i2 < 0 || i2 >= d2) {
            throw "Out of bounds";
        }
#endif
        return b[i1 * d2 + i2];
    }

    arr<T> operator[](int at) {
#ifdef LOCAL
        if (at < 0 || at >= d1) {
            throw "Out of bounds";
        }
#endif
        return arr<T>(b + at * d2, d2);
    }
};

template<typename T>
class arr3d {
    T *b;
    T *e;
    int d1;
    int d2;
    int d3;
    int shift;
    int sz;

public:
    arr3d() : b(nullptr), e(nullptr), d1(0), d2(0), d3(0), shift(0), sz(0) {}

    arr3d(int d1, int d2, int d3) : d1(d1), d2(d2), d3(d3), shift(d2 * d3), sz(d1 * d2 * d3) {
        b = new T[sz];
        e = b + sz;
    }

    arr3d(int d1, int d2, int d3, const T &init) : d1(d1), d2(d2), d3(d3), shift(d2 * d3), sz(d1 * d2 * d3) {
        b = new T[sz];
        e = b + sz;
        fill(b, e, init);
    }

    arr3d(T *b, int d1, int d2, int d3) : b(b), e(b + d1 * d2 * d3), d1(d1), d2(d2), d3(d3), shift(d2 * d3),
                                          sz(d1 * d2 * d3) {}

    size_t size() const {
        return sz;
    }

    size_t dim1() const {
        return d1;
    }

    size_t dim2() const {
        return d2;
    }

    size_t dim3() const {
        return d3;
    }

    T *begin() {
        return b;
    }

    T *end() {
        return e;
    }

    T &operator()(int i1, int i2, int i3) {
#ifdef LOCAL
        if (i1 < 0 || i1 >= d1 || i2 < 0 || i2 >= d2 || i3 < 0 || i3 >= d3) {
            throw "Out of bounds";
        }
#endif
        return b[i1 * shift + i2 * d3 + i3];
    }

    const T &operator()(int i1, int i2, int i3) const {
#ifdef LOCAL
        if (i1 < 0 || i1 >= d1 || i2 < 0 || i2 >= d2 || i3 < 0 || i3 >= d3) {
            throw "Out of bounds";
        }
#endif
        return b[i1 * shift + i2 * d3 + i3];
    }

    arr2d<T> operator[](int at) {
#ifdef LOCAL
        if (at < 0 || at >= d1) {
            throw "Out of bounds";
        }
#endif
        return arr2d<T>(b + at * shift, d2, d3);
    }
};


inline bool isWhitespace(int c) {
    return isspace(c) || c == EOF;
}

class Input {
private:
    istream &in;
    bool exhausted = false;

    inline int get() {
        if (exhausted) {
            throw "Input exhausted";
        }
        int c = in.get();
        if (c == EOF) {
            exhausted = true;
        }
        return c;
    }

    template<typename T>
    inline T readInteger() {
        skipWhitespace();
        int c = get();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = get();
        }
        T res = 0;
        do {
            if (!isdigit(c)) {
                throw "Number format error";
            }
            res *= 10;
            res += c - '0';
            c = get();
        } while (!isWhitespace(c));
        return res * sgn;
    }

    void initArrays(int) {}

    template<typename T, class...Vs>
    void initArrays(int n, arr<T> &array, Vs &...vs) {
        array = arr<T>(n);
        initArrays(n, vs...);
    }

    void readImpl(int) {}

    template<typename T, class...Vs>
    void readImpl(int i, arr<T> &arr, Vs &...vs) {
        arr[i] = readType<T>();
        readImpl(i, vs...);
    }

public:
    Input(istream &in) : in(in) {};

    inline void skipWhitespace() {
        int c;
        while (isWhitespace(c = in.peek()) && c != EOF) {
            in.get();
        }
        if (c == EOF) {
            exhausted = true;
        }
    }

    inline int readInt() {
        return readInteger<int>();
    }

    ll readLong() {
        return readInteger<ll>();
    }

    string readString() {
        skipWhitespace();
        int c = get();
        if (c == EOF) {
            throw "Input exhausted";
        }
        vec<char> res;
        do {
            res.push_back(c);
        } while (!isWhitespace(c = get()));
        return string(all(res));
    }

    arri readIntArray(int size) {
        return readArray<int>(size);
    }

    template<typename T>
    T readType() {
        throw "Operation not supported";
    }

    template<typename U, typename V>
    pair<U, V> readType() {
        U first = readType<U>();
        V second = readType<V>();
        return make_pair(first, second);
    }

    template<typename T>
    arr<T> readArray(int n) {
        arr<T> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = readType<T>();
        }
        return res;
    }


    template<class...Vs>
    void readArrays(int n, Vs &...vs) {
        initArrays(n, vs...);
        for (int i = 0; i < n; i++) {
            readImpl(i, vs...);
        }
    }

    template<typename U, typename V>
    arr<pair<U, V> > readArray(int n) {
        arr<pair<U, V> > res(n);
        for (int i = 0; i < n; i++) {
            res[i] = readType<U, V>();
        }
        return res;
    }

    template<typename T>
    arr2d<T> readTable(int rows, int cols) {
        arr2d<T> result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result(i, j) = readType<T>();
            }
        }
        return result;
    }

    string readLine() {
        skipWhitespace();
        int c = get();
        if (c == EOF) {
            throw "Input exhausted";
        }
        int length = 0;
        vec<char> res;
        do {
            res.push_back(c);
            if (!isWhitespace(c)) {
                length = res.size();
            }
            c = get();
        } while (c != '\n' && c != '\r' && c != EOF);
        return string(res.begin(), res.begin() + length);
    }

    double readDouble() {
        skipWhitespace();
        int c = get();
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = get();
        }
        double res = 0;
        do {
            if (tolower(c) == 'e') {
                return sgn * res * dPower(10, readInt());
            }
            if (!isdigit(c)) {
                throw "Number format error";
            }
            res *= 10;
            res += c - '0';
            c = get();
        } while (!isWhitespace(c) && c != '.');
        if (c == '.') {
            double add = 0;
            int length = 0;
            c = get();
            do {
                if (tolower(c) == 'e') {
                    return sgn * (res + add * dPower(10, -length)) * dPower(10, readInt());
                }
                if (!isdigit(c)) {
                    throw "Number format error";
                }
                add *= 10;
                add += c - '0';
                length++;
                c = get();
            } while (!isWhitespace(c));
            res += add * dPower(10, -length);
        }
        return res * sgn;
    }

    char readChar() {
        skipWhitespace();
        int c = get();
        if (c == EOF) {
            throw "Input exhausted";
        }
        return c;
    }

    bool isExhausted() { return exhausted; }
};

template<>
double Input::readType() {
    return readDouble();
}

template<>
int Input::readType() {
    return readInt();
}

template<>
ll Input::readType() {
    return readLong();
}

template<>
char Input::readType() {
    return readChar();
}

template<>
string Input::readType() {
    return readString();
}


class Output {
private:
    ostream &out;

    template<typename T>
    void printSingle(const T &value) {
        out << value;
    }

    template<typename T>
    void printSingle(const vec<T> &array) {
        size_t n = array.size();
        for (int i = 0; i < n; ++i) {
            out << array[i];
            if (i + 1 != n) {
                out << ' ';
            }
        }
    }

    template<typename T>
    void printSingle(const arr<T> &array) {
        size_t n = array.size();
        for (int i = 0; i < n; ++i) {
            out << array[i];
            if (i + 1 != n) {
                out << ' ';
            }
        }
    }

    template<typename T>
    void printSingle(const arr2d<T> &array) {
        size_t n = array.dim1();
        size_t m = array.dim2();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                out << array(i, j);
                if (j + 1 != m) {
                    out << ' ';
                }
            }
            if (i + 1 != n) {
                out << '\n';
            }
        }
    }

    template<typename T, typename U>
    void printSingle(const pair<T, U> &value) {
        out << value.first << ' ' << value.second;
    }

public:
    Output(ostream &out) : out(out) {
        out << fixed << setprecision(20);
    }

    void print() {}

    template<typename T, typename...Targs>
    void print(const T &first, const Targs... args) {
        printSingle(first);
        if (sizeof...(args) != 0) {
            out << ' ';
            print(args...);
        }
    }

    template<typename...Targs>
    void printLine(const Targs... args) {
        print(args...);
        out << '\n';
    }

    void flush() {
        out.flush();
    }
};


class NumberIterator : iterator<forward_iterator_tag, int> {
public:
    int v;

    NumberIterator(int v) : v(v) {}

    operator int &() { return v; }

    int operator*() { return v; }
};

class range : pii {
public:
    range(int begin, int end) : pii(begin, max(begin, end)) {}

    range(int n) : pii(0, max(0, n)) {}

    NumberIterator begin() {
        return first;
    }

    NumberIterator end() {
        return second;
    }
};


class ReverseNumberIterator : public NumberIterator {
public:
    ReverseNumberIterator(int v) : NumberIterator(v) {}

    ReverseNumberIterator &operator++() {
        --v;
        return *this;
    }
};

class RevRange : pii {
public:
    RevRange(int begin, int end) : pii(begin - 1, min(begin, end) - 1) {}

    RevRange(int n) : pii(n - 1, min(n, 0) - 1) {}

    ReverseNumberIterator begin() {
        return first;
    }

    ReverseNumberIterator end() {
        return second;
    }
};


template<typename T>
inline void unique(vec<T> &v) {
    v.resize(unique(all(v)) - v.begin());
}

arri createOrder(int n) {
    arri order(n);
    for (int i = 0; i < n; i++) {
        order[i] = i;
    }
    return order;
}

template<class Collection, typename Iterator>
inline void addAll(Collection &v, Iterator begin, Iterator end) {
    v.insert(v.end(), begin, end);
}

template<typename Collection>
arri getQty(const Collection &arr, int length) {
    arri res(length);
    for (int i : arr) {
        res[i]++;
    }
    return res;
}

template<typename Collection>
arri getQty(const Collection &arr) {
    return getQty(arr, *max_element(all(arr)) + 1);
}

template<class Collection>
void collect(Collection &) {}

template<class Collection, class ...Vs>
void collect(Collection &all, Collection &a, Vs &...vs) {
    addAll(all, all(a));
    collect(all, vs...);
}

void replace(const vi &) {}

template<class ...Vs>
void replace(const vi &all, vi &a, Vs &...vs) {
    for (int &i : a) {
        i = lower_bound(all(all), i) - all.begin();
    }
    replace(all, vs...);
}

template<class ...Vs>
void replace(const vi &all, arri &a, Vs &...vs) {
    for (int &i : a) {
        i = lower_bound(all(all), i) - all.begin();
    }
    replace(all, vs...);
}

template<class ...Vs>
vi compress(Vs &...vs) {
    vi vals;
    collect(vals, vs...);
    sort(all(vals));
    unique(vals);
    replace(vals, vs...);
    return vals;
}


template<typename W, typename C>
class WeightedFlowEdge {
private:
    WeightedFlowEdge<W, C> *reverseEdge;

public:
    const int from;
    const int to;
    W weight;
    C capacity;
    int id;

    WeightedFlowEdge(int from, int to, W weight, C capacity) : from(from), to(to), weight(weight), capacity(capacity) {
        reverseEdge = new WeightedFlowEdge(this);
    }

    WeightedFlowEdge<W, C> *transposed() { return nullptr; }

    WeightedFlowEdge<W, C> *reverse() { return reverseEdge; }

    void push(C flow) {
        capacity -= flow;
        reverseEdge->capacity += flow;
    }

    C flow() const {
        return reverseEdge->capacity;
    }

private:
    WeightedFlowEdge(WeightedFlowEdge<W, C> *reverse) : from(reverse->to), to(reverse->from), weight(-reverse->weight),
                                                        capacity(0) {
        reverseEdge = reverse;
    }
};

template<typename C>
class FlowEdge {
private:
    FlowEdge<C> *reverseEdge;

public:
    const int from;
    const int to;
    C capacity;
    int id;

    FlowEdge(int from, int to, C capacity) : from(from), to(to), capacity(capacity) {
        reverseEdge = new FlowEdge(this);
    }

    FlowEdge<C> *transposed() { return nullptr; }

    FlowEdge<C> *reverse() { return reverseEdge; }

    void push(C flow) {
        capacity -= flow;
        reverseEdge->capacity += flow;
    }

    C flow() const {
        return reverseEdge->capacity;
    }

private:
    FlowEdge(FlowEdge<C> *reverse) : from(reverse->to), to(reverse->from), capacity(0) {
        reverseEdge = reverse;
    }
};

template<typename W>
class WeightedEdge {
public:
    const int from;
    const int to;
    W weight;
    int id;

    WeightedEdge(int from, int to, W weight) : from(from), to(to), weight(weight) {
    }

    WeightedEdge<W> *transposed() { return nullptr; }

    WeightedEdge<W> *reverse() { return nullptr; }
};

template<typename W>
class BiWeightedEdge {
private:
    BiWeightedEdge<W> *transposedEdge;

public:
    const int from;
    const int to;
    W weight;
    int id;

    BiWeightedEdge(int from, int to, W weight) : from(from), to(to), weight(weight) {
        transposedEdge = new BiWeightedEdge(this);
    }

    BiWeightedEdge<W> *transposed() { return transposedEdge; }

    BiWeightedEdge<W> *reverse() { return nullptr; }

private:
    BiWeightedEdge(BiWeightedEdge<W> *transposed) : from(transposed->to), to(transposed->from),
                                                    weight(transposed->weight) {
        transposedEdge = transposed;
    }
};

class BaseEdge {
public:
    const int from;
    const int to;
    int id;

    BaseEdge(int from, int to) : from(from), to(to) {
    }

    BaseEdge *transposed() { return nullptr; }

    BaseEdge *reverse() { return nullptr; }
};

class BiEdge {
private:
    BiEdge *transposedEdge;

public:
    const int from;
    const int to;
    int id;

    BiEdge(int from, int to) : from(from), to(to) {
        transposedEdge = new BiEdge(this);
    }

    BiEdge *transposed() { return transposedEdge; }

    BiEdge *reverse() { return nullptr; }

private:
    BiEdge(BiEdge *transposed) : from(transposed->to), to(transposed->from) {
        transposedEdge = transposed;
    }
};

template<class Edge>
class Graph {
public:
    int vertexCount;
    int edgeCount = 0;
private:
    arr<vec<Edge *> > edges;

public:
    Graph(int vertexCount) : vertexCount(vertexCount), edges(vertexCount, vec<Edge *>()) {}

    void addEdge(Edge *edge) {
        edge->id = edgeCount;
        edges[edge->from].push_back(edge);
        Edge *reverse = edge->reverse();
        if (reverse != nullptr) {
            reverse->id = edgeCount;
            edges[reverse->from].push_back(reverse);
        }
        Edge *transposed = edge->transposed();
        if (transposed != nullptr) {
            edges[transposed->from].push_back(transposed);
            transposed->id = edgeCount;
            Edge *transRev = transposed->reverse();
            if (transRev != nullptr) {
                edges[transRev->from].push_back(transRev);
                transRev->id = edgeCount;
            }
        }
        edgeCount++;
    }

    template<typename...Ts>
    void addEdge(Ts...ts) {
        addEdge(new Edge(ts...));
    }

    vec<Edge *> &operator[](int at) {
        return edges[at];
    }
};


//#pragma comment(linker, "/STACK:200000000")

class TaskE {
public:
    void solve(istream &inp, ostream &outp) {
        Input in(inp);
        Output out(outp);

        int n = in.readInt();
        int m = in.readInt();
        arri a, b;
        in.readArrays(m, a, b);
        decreaseByOne(a, b);

        Graph<BiEdge> graph(n);
        for (int i : range(m)) {
            graph.addEdge(a[i], b[i]);
        }
        vec<vi> paths;
        vi stack;
        arr<bool> visited(n, false);
        arr<bool> onStack(n, false);
        function<void(int, int)> dfs = [&](int vert, int last) {
            if (visited[vert]) {
                if (!onStack[vert]) {
                    return;
                }
                vi cur;
                int at = stack.size() - 1;
                while (cur.size() < 2 || a[stack[at]] != vert && b[stack[at]] != vert) {
                    cur.push_back(stack[at--]);
                }
                cur.push_back(stack[at]);
                paths.push_back(cur);
                return;
            }
            visited[vert] = true;
            onStack[vert] = true;
            for (auto *e : graph[vert]) {
                if (e->to == last) {
                    continue;
                }
                stack.push_back(e->id);
                dfs(e->to, vert);
                stack.pop_back();
            }
            onStack[vert] = false;
        };
        for (int i : range(n)) {
            if (!visited[i]) {
                dfs(i, -1);
            }
        }
        arri delta(m, -1);
        arri mult(m);
        for (const auto &path : paths) {
            int at = min_element(all(path)) - path.begin();
            vi pp(path.begin() + at, path.end());
            addAll(pp, path.begin(), path.begin() + at);
            auto stuff = [&]() -> bool {
                bool good = true;
                for (int i = 0; i < path.size() - 1; i++) {
                    if (pp[i] > pp[i + 1]) {
                        good = false;
                        break;
                    }
                }
                if (good) {
                    delta[pp[0]] = pp.back();
                    mult[pp[0]] = 2;
                }
                return good;
            };
            if (stuff()) {
                continue;
            }
            reverse(pp.begin() + 1, pp.end());
            if (stuff()) {
                continue;
            }
            int i;
            for (i = 0; i < pp.size() - 1; i++) {
                if (pp[i] > pp[i + 1]) {
                    break;
                }
            }
            int j;
            for (j = pp.size() - 2; j >= 0; j--) {
                if (pp[j] < pp[j + 1]) {
                    break;
                }
            }
            if (i != j + 1) {
                continue;
            }
            delta[pp[0]] = pp[i];
            mult[pp[0]] = 1;
        }
        arri answer(n, 1);
        arri store(m);
        for (int i : RevRange(m)) {
            int res = answer[a[i]] + answer[b[i]];
            store[i] = res;
            if (delta[i] != -1) {
                res -= store[delta[i]];
            }
            answer[a[i]] = answer[b[i]] = res;
        }
        for (int &i : answer) {
            i--;
        }
        out.printLine(answer);
    }
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    TaskE solver;
    std::istream &in(std::cin);
    std::ostream &out(std::cout);
    solver.solve(in, out);
    return 0;
}