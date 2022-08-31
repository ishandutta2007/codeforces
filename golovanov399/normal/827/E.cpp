#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int

using namespace std;

#define complex complex<double>

inline int nxt() {
    int x;
    cin >> x;
    return x;
}

const double pi = acosl(-1);
const int MAXPOWER = 21;
const int MAXN = 1 << MAXPOWER;

complex angles[MAXN];
int revs[MAXN];

const double eps = 1e-8;

int rev(int x) {
	int y = 0;
	for (int i = 0; i < MAXPOWER; ++i) {
		if (x & 1) {
			y |= 1;
		}
		x >>= 1;
		y <<= 1;
	}
	return y;
}

inline int rev(int x, int power) {
	return revs[x] >> (MAXPOWER - power + 1);
}

complex buffer[MAXN];

void fft(vector<complex>& a, bool inverse = false) {
	int n = a.size();
	int pwr = __builtin_ctz(n);

	// vector<complex> buffer(n);
	for (int i = 0; i < n; ++i) {
		int j = rev(i, pwr);
		if (i < j) {
			swap(a[i], a[j]);
		}
	}

	if (n == 1) {
		return;
	}
	if (n == 2) {
		auto v = a[1];
		a[1] = a[0] - v;
		a[0] += v;
		return;
	}

	for (int start = 0; start < n; start += 2) {
		auto tmp = a[start + 1];
		// buffer[start] = a[start] + tmp;
		// buffer[start + 1] = a[start] - tmp;
		a[start + 1] = a[start] - tmp;
		a[start] += tmp;
	}
	// a.swap(buffer);
	// memcpy(a.data(), buffer, n * sizeof(complex));
	// copy(buffer, buffer + n * sizeof(complex), a.data());

	for (int p = 1; p < pwr; ++p) {
		int len = (1 << p);
		for (int start = 0; start < n; start += len * 2) {
			for (int i = 0; i < len; ++i) {
				complex rt = angles[i << (MAXPOWER - p - 1)];
				if (inverse) {
					rt = conj(rt);
				}
				auto tmp = rt * a[start + len + i];
				buffer[start + i] = a[start + i] + tmp;
				buffer[start + len + i] = a[start + i] - tmp;
			}
			for (int i = 0; i < len + len; ++i) {
				a[start + i] = buffer[start + i];
			}
		}

		// a.swap(buffer);
		// memcpy(a.data(), buffer, n * sizeof(complex));
		// copy(buffer, buffer + n * sizeof(complex), a.data());
	}

	if (inverse) {
		for (int i = 0; i < n; ++i) {
			a[i] /= n;
		}
	}
}

template <typename T>
vector<T> mult(const vector<T>& a, const vector<T>& b) {
	int n = 1, pwr = 0;
	while (n < (int)a.size() || n < (int)b.size()) {
		n <<= 1;
		pwr += 1;
	}
	n *= 2;
	pwr += 1;
	vector<complex> fft_a(n), fft_b(n);
	for (int i = 0; i < (int)a.size(); ++i) {
		fft_a[i] = a[i];
	}
	for (int i = 0; i < (int)b.size(); ++i) {
		fft_b[i] = b[i];
	}
	fft(fft_a), fft(fft_b);

	// for (auto x : fft_a) {
	// 	cerr << x << " ";
	// }
	// cerr << "\n";
	// for (auto x : fft_b) {
	// 	cerr << x << " ";
	// }
	// cerr << "\n---\n";

	for (int i = 0; i < n; ++i) {
		fft_a[i] *= fft_b[i];
	}
	fft(fft_a, true);

	// for (auto x : fft_a) {
	// 	cerr << x.real() << " ";
	// }
	// cerr << "\n";

	vector<T> res(n);
	for (int i = 0; i < n; ++i) {
		res[i] = floor(fft_a[i].real() + 0.5);
	}
	while (res.size() && abs(res.back()) < eps) {
		res.pop_back();
	}
	return res;
}

#define ANGLES_POWER MAXPOWER
#define ANGLES MAXN
#define w angles

/*vector<complex> fft(vector<complex> a, bool inverse)
{
    // two extend
    
    int power = 0;
    while (power < 
}*/

const int maxN = 500500;
bool isNotPrime[maxN];
vector<int> primes;

void sieve()
{
    for (int i = 2; i < maxN; i++)
        if (!isNotPrime[i])
        {
            primes.push_back(i);
            if (i * (long long)i >= maxN) continue;
            for (int j = i * i; j < maxN; j += i)
                isNotPrime[j] = true;
        }
}

int main()
{
    sieve();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    const double pi = acos(-1);
	for (int i = 0; i < MAXN; ++i) {
		angles[i] = {cos(2 * pi * i / MAXN), sin(2 * pi * i / MAXN)};
		revs[i] = rev(i);
	}
    
    bool read = true;
    
    int nt;
    if (read)
        cin >> nt;
    else
        nt = 1;
    
    
    for (int i = 0; i < nt; i++)
    //while (true)
    {
        int n;
        string s;
        if (read)
            cin >> n >> s;
        else
        {
            n = rand() % 100 + 1;
            //n = 500000;
            //n = 100;
            s = string(n, '?');
            for (int i = 0; i < n; i++)
                s[i] = "VK?"[rand() % 3];
        }
        n = s.length();
        
        //printf("string: '%s'\n", s.c_str());
        
        int power = 0;
        while ((1 << power) < n) power++;
        
        // 2^power >= n;
        
        power++;
        vector<int> a(1 << power), b(1 << power);
        for (int i = 0; i < n; i++)
            if (s[i] == 'V')
            {
                a[n - i] = 1;
            }
            else if (s[i] == 'K')
            {
                b[i] = 1;
            }
            
        a = mult(a, b);
        
        //for (int i = 0; i < (1 << power); i++)
        //    printf("%.9f %.9f\n", a[i].real(), a[i].imag());
        
        vector<char> shift(n);
        
        for (int i = 0; i < n; i++)
        {
            if (a[n + i])
            {
                shift[i] = true;
            }
            
            if (i != 0 && a[i])
            {
                shift[n - i] = true;
            }
        }
            
#if 0
        vector<char> shift_exp(n);
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (s[i] == 'V' && s[j] == 'K')
                    shift_exp[j - i] = true;
            
        for (int i = 0; i < n; i++)
            printf("shift %d: %d, expected: %d\n", i, shift[i], shift_exp[i]);
        
        assert(shift == shift_exp);
#endif

        //for (int t = 0; t < 5; t++) printf("%d ", primes[t]); printf("\n");
     
        for (int i = n - 1; i >= 2; i--)
            if (shift[i])
            {
                int j = i;
                vector<int> pdivs;
                //printf("%d is banned\n", i);
                for (int x: primes)
                {
                    //printf("test %d\n", x);
                    if (x * x > j) break;
                    if (j % x == 0)
                    {
                        pdivs.push_back(x);
                        //printf("ban %d too\n", i / x);
                        //break;
                        
                        while (j % x == 0) j /= x;
                    }
                }
                
                if (j != 1)
                    pdivs.push_back(j);
                
                for (int y: pdivs)
                    shift[i / y] = true;
            }
            
        vector<int> answer;
        
        shift[0] = true;
        for (int i = 0; i < n; i++)
            if (!shift[i])
                answer.push_back(i);
        answer.push_back(n);
            
        cout << answer.size() << '\n';
        for (int x: answer) cout << x << ' ';
        cout << '\n';
        
#if 0
        vector<int> answer_exp;
        for (int shift = 1; shift <= n; shift++)
        {
            vector<vector<char>> letters(shift);
            
            for (int i = 0; i < n; i++)
                if (s[i] != '?')
                    letters[i % shift].push_back(s[i]);
                
            bool fail = false;
            for (int i = 0; i < shift; i++)
            {
                sort(letters[i].begin(), letters[i].end());
                if (!letters[i].empty() && letters[i][0] != letters[i].back())
                {
                    fail = true;
                    break;
                }
            }
            
            //printf("shift %d: %d\n", shift, fail);
            
            if (!fail)
                answer_exp.push_back(shift);
        }
        
        cout.flush();
        printf("expected: ");
        for (int x: answer_exp) printf("%d ", x); printf("\n"); fflush(stdout);
        assert(answer == answer_exp);
#endif
    }
    
    return 0;
}