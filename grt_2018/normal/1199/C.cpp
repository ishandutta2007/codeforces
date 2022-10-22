    #include <bits/stdc++.h>
     
    using namespace std;
     
    using ll = long long;
    using vi = vector<int>;
    using pi = pair<int,int>;
    #define ST first
    #define ND second
    #define PB push_back
     
    const int nax = 4*100*1000+10;
    int n,I;
    int a[nax];
    int ans = 1000*1000*1000;
    int logg[2*nax];
     
    int main() {
    	ios_base::sync_with_stdio(0);
    	cin.tie(0);
    	cin>>n>>I;
    	I*=8;
    	for(int i=1; i<=n;i++) cin>>a[i];
    	int p = 1;
    	while((1<<p)<=2*n) {
    		logg[(1<<p)] = p;
    		p++;
    	}
    	for(int i=2*n; i>=2;i--) {
    		if(logg[i]==0) logg[i] = logg[i+1];
    	}
    	sort(a+1,a+n+1);
    	int mak = I/n, atmost=-1;
    	for(int i=1; i<=n;i++) if(logg[i]<=mak) atmost = i;
    	int wsk = 1, diff = 1;
    	//cout<<atmost<<"\n";
    	while(wsk+1<=n&&a[wsk+1]==a[wsk]) wsk++;
    	for(int i=1; i<=n;i++) {
			while(wsk+1<=n&&diff+1<=atmost) {
				diff++; wsk++;
				while(wsk+1<=n&&a[wsk+1]==a[wsk]) wsk++;
			}
			ans = min(ans,n-(wsk-i+1));
			if(a[i+1]!=a[i]) diff--;
		}
		cout<<ans;
    }