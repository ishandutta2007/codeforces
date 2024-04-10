    #include <bits/stdc++.h>
    using namespace std;
     
    const int nax = 100*1000;
    int T,n;
    int a[nax];
     
    int main() {
    	ios_base::sync_with_stdio(0);
    	cin.tie(0);
    	cin>>T;
    	while(T--) {
    		cin>>n;
    		for(int i=0; i<n;i++) cin>>a[i];
    		sort(a,a+n);
    		cout<<min(a[n-2] - 1,n-2)<<"\n";
    	}
    	return 0;
    }