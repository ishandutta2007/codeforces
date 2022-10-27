#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ull mod = (1ULL<<58);

struct Poly{
	ull x[5];
	Poly(){
		for(int i = 0; i < 5; i++){
			x[i] = 0;
		}
	}
	Poly(initializer_list<ull> a){
		int i = 0;
		for(auto xx : a){
			x[i++] = xx;
		}
		for(; i < 5; i++){
			x[i] = 0;
		}
	}
	Poly(const Poly &a){
		for(int i = 0; i < 5; i++){
			x[i] = a.x[i];
		}
	}
	Poly& operator=(const Poly &a){
		for(int i = 0; i < 5; i++){
			x[i] = a.x[i];
		}
		return *this;
	}
	Poly& operator+=(const Poly &a){
		for(int i = 0; i < 5; i++){
			x[i] += a.x[i];
		}
		return *this;
	}
	Poly operator*(const Poly &a){
		Poly c;
		for(int i = 0; i < 5; i++){
			for(int j = 0; j < 5; j++){
				if(i + j < 5)c.x[i+j] += a.x[i]*x[j];
				else c.x[i+j-5] -= a.x[i]*x[j];
			}
		}
		return c;
	}

	void print(){
		for(int i = 0; i < 5; i++){
			cout<<x[i]<<" ";
		}
		cout<<endl;
	}
};

Poly rt[2][10][10];

void Init(){
	Poly root = {0, 1};
	Poly cur = {1};
	for(int i = 0; i < 10; i++){
		Poly tmp = {1};
		for(int j = 0; j < 10; j++){
			rt[0][i][j] = tmp;
			tmp = tmp*cur;
		}
		cur = cur*root;
	}
	root = {0, 0, 0, 0, (ull)-1};
	cur = {1};
	for(int i = 0; i < 10; i++){
		Poly tmp = {1};
		for(int j = 0; j < 10; j++){
			rt[1][i][j] = tmp;
			tmp = tmp*cur;
		}
		cur = cur*root;
	}
}

void dft(Poly arr[], Poly brr[], int inv){
	for(int i = 0; i < 10; i++){
		brr[i] = {0};
		for(int j = 0; j < 10; j++){
			brr[i] += arr[j]*rt[inv][i][j];
		}
	}
}

Poly arr[10], brr[10];
int pws[] = {1, 10, 100, 1000, 10000, 100000};

void transform(Poly a[], int inv){
	for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 100000; ++j) {
            if (j % pws[i + 1] / pws[i] == 0) {
                for (int k = 0; k < 10; ++k) arr[k] = a[j + pws[i] * k];
                dft(arr, brr, inv);
                for (int k = 0; k < 10; ++k) a[j + pws[i] * k] = brr[k];
            }
        }
    }
}

Poly power(Poly &a, int n){
	Poly ans = {1};
	while(n){
		if(n&1)ans = ans*a;
		a = a*a;
		n >>= 1;
	}
	return ans;
}

ull power(ull a, ull n){
	ull ans = 1;
	while(n){
		if(n&1)ans = ans*a;
		a = a*a;
		n >>= 1;
	}
	return ans;
}

void reduce(Poly &a){
	a.x[3] += a.x[4];
	a.x[2] -= a.x[4];
	a.x[1] += a.x[4];
	a.x[0] -= a.x[4];
}

Poly a[100000];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Init();
    int n, x;
    cin>>n;
    for(int i = 0; i < n; i++){
    	cin>>x;
    	a[x].x[0]++;
    }
    transform(a, 0);
    for(int i = 0; i < 100000; i++){
    	// cout<<a[i].x[0]<<endl;
    	a[i] = power(a[i], n);
    }
    transform(a, 1);
    ll inv = power(3125, (1ULL<<63)-1);
    for(int i = 0; i < n; i++){
    	reduce(a[i]);
    	ll ans = a[i].x[0];
    	ans >>= 5;
    	ans *= inv;
    	cout<<ans%mod<<endl;
    }
}