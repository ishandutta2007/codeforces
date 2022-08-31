#include<iostream>
#include<algorithm>
using namespace std;
int main (){
ios::sync_with_stdio(false);
    int n,k,q;
    cin >> n >> k >> q;
    int t[n+1],c[k+2];
    for(int i=1; i<=n ;i++){
    	cin >> t[i];
	}
	for(int i=1; i<=k ;i++){
		c[i]=-1;
	}
	int r,s;
	int ptr=1;
	for(int i=1; i<=q ;i++){
		cin >> r >> s;
		if(r==1){
			c[ptr]=s;
			r=ptr;
			if(ptr<=k){
				ptr++;
			}
			while(r>1 && t[c[r]]>t[c[r-1]]){
				swap(c[r],c[r-1]);
				r--;
			}
		}
		else{
			bool ok=false;
			for(int j=1; j<=k ;j++){
				if(s==c[j]){
					ok=true;
					break;
				}
			}
			if(ok){
				cout << "YES\n";
			}
			else{
				cout << "NO\n";
			}
		}
	}
}