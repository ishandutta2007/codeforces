#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <bitset>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <set>
#include <complex>

using namespace std;

const int SIZE = 1 << 10;

int pointer = SIZE;
char buffer[SIZE];

char Advance() {
    if (pointer == SIZE) {
        fread(buffer, 1, SIZE, stdin);
        pointer = 0;
    }
    return buffer[pointer++];
}

int Read() {
    int answer = 0;
    char ch = Advance();
    while (!isdigit(ch))
        ch = Advance();
    while (isdigit(ch)) {
        answer = answer * 10 + ch - '0';
        ch = Advance();
    }
    return answer;
}

const int SIGMA = 6;
const int MAXN = 125000;
const int MAXNFFT = 262144;
const double PI = acos(-1);

char s[1 + MAXN], t[1 + MAXN];
int dad[SIGMA];

struct Complex {
    double re, img;

    Complex() {
        re = img = 0;
    }

    Complex(double a) {
        re = a, img = 0;
    }

    Complex(double a, double b) {
        re = a, img = b;
    }

    double real() {
        return re;
    }

    Complex operator * (Complex a) {
        return Complex(re * a.re - img * a.img, re * a.img + img * a.re);
    }

    Complex operator *= (Complex a) {
        return *this =  *this * a;
    }

    Complex operator + (Complex a) {
        return Complex(re + a.re, img + a.img);
    }

    Complex operator - (Complex a) {
        return Complex(re - a.re, img - a.img);
    }
};

int Reversal(int value, int bits) {
    int answer = 0;
    for (int i = 0; i < bits; i++)
        if (value & (1 << i))
            answer |= (1 << (bits - i - 1));
    return answer;
}

Complex fa[1 + MAXNFFT], fb[1 + MAXNFFT];

void FFT(Complex a[], bool inverse, int n) {
    double sign = 1;
    if (inverse)
        sign = -1;
    int bits = 0;
    while ((1 << bits) < n)
        bits++;
    for (int i = 0; i < n; i++)
        if (i < Reversal(i, bits))
            swap(a[i], a[Reversal(i, bits)]);
    for (int step = 2; step <= n; step *= 2) {
        double angle = 2 * PI / step * sign;
        Complex omega (cos(angle), sin(angle));
        for (int i = 0; i < n; i += step) {
            Complex power (1, 0);
            for (int j = 0; j < step / 2; j++) {
                Complex u = a[i + j], v = a[i + j + step / 2] * power;
                a[i + j] = u + v;
                a[i + j + step / 2] = u - v;
                power = power * omega;
            }
        }
    }
    if (inverse)
        for (int i = 0; i < n; i++)
            a[i] = a[i] * (1.0 / n);
}

void Multiply(int a[], int b[], int c[], int na, int nb, int &nc) {
    int n = 1;
    while (n < na + nb)
        n *= 2;
    for (int i = 0; i < na; i++)
        fa[i] = Complex(a[i], 0);
    for (int i = na; i < n; i++)
        fa[i] = Complex();
    for (int i = 0; i < nb; i++)
        fb[i] = Complex(b[i], 0);
    for (int i = nb; i < n; i++)
        fb[i] = Complex();
    FFT(fa, false, n);
    FFT(fb, false, n);
    for (int i = 0; i < n; i++)
        fa[i] = fa[i] * fb[i];
    FFT(fa, true, n);
    for (int i = 0; i < n; i++) {
        int x = (int)(fa[i].re + 0.5);
        c[i] = x;
    }
    nc = na + nb - 1;
}

int text[1 + MAXNFFT], pattern[1 + MAXNFFT], result[1 + MAXNFFT];
bool match[SIGMA][SIGMA][1 + MAXN];

void Initialize() {
    for (int i = 0; i < SIGMA; i++)
        dad[i] = i;
}

int FindDad(int node) {
    if (dad[node] == node)
        return node;
    return dad[node] = FindDad(dad[node]);
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    scanf("%s%s", s + 1, t + 1);
    srand(time(0));
    int n = strlen(s + 1), m = strlen(t + 1);
    for (int a = 0; a < SIGMA; a++)
        for (int b = 0; b < SIGMA; b++) {
            for (int i = 1; i <= n; i++)
                if (s[i] - 'a' == a)
                    text[i] = 1;
                else
                    text[i] = 0;
            for (int j = 1; j <= m; j++)
                if (t[j] - 'a' == b)
                    pattern[m - j + 1] = 1;
                else
                    pattern[m - j + 1] = 0;
            int temp;
            Multiply(text, pattern, result, n + 1, m + 1, temp);
            for (int i = 1; i <= n - m + 1; i++)
                if (result[m + i])
                    match[a][b][i] = true;
        }
    for (int i = 1; i <= n - m + 1; i++) {
        Initialize();
        int answer = 0;
        for (int a = 0; a < SIGMA; a++)
            for (int b = a + 1; b < SIGMA; b++)
                if (match[a][b][i] || match[b][a][i]) {
                    int x = FindDad(a), y = FindDad(b);
                    if (x != y) {
                        answer++;
                        if (rand() % 2)
                            dad[x] = y;
                        else
                            dad[y] = x;
                    }
                }
        printf("%d ", answer);
    }
    return 0;
}