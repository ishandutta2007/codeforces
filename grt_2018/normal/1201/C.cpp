    #include <bits/stdc++.h>

    using namespace std;

    using ll = long long;
    using vi = vector<int>;
    using pi = pair<int,int>;
    #define ST first
    #define ND second
    #define PB push_back
    #define _ ios_base::sync_with_stdio(0); cin.tie(0);
    //mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    const int nax = 200*1000+10;
    int n,k;
    int a[nax];

    bool check(int x) {
    	ll s = 0;
    	for(int i=n/2; i<n;i++) {
    		if(a[i]<x) s+=x-a[i];
    	}
    	return s<=k;
    }

    int main() {_
    	cin>>n>>k;
    	for(int i=0; i<n;i++) {
    		cin>>a[i];
    	}
    	sort(a,a+n);
    	ll pocz = a[n/2], kon = a[n/2]+k, sr;
    	while(pocz<=kon) {
    		sr=(pocz+kon)/2;
    		if(check(sr)) pocz=sr+1;
    		else kon=sr-1;
    	}
    	cout<<pocz-1;
    }