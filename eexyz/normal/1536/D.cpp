#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define pb push_back
#define ll long long
#define pn cout<<"NO\n"
#define py cout<<"YES\n" 
int T,i,j,d,hd,n,ee,f1,f2,k,fl,a[N],ans[N],mx,x,y,v,s1[N],st[N],vst[N];
char s[N];
set<int>p;
set<int>::iterator it; 
int main(){
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>n;p.clear();
		for(i=1;i<=n;++i)cin>>a[i];
		p.insert(a[1]);fl=0;
		for(i=2;i<=n;++i){
			if(a[i]!=a[i-1]){
				if(a[i]>a[i-1]){
					it=p.lower_bound(a[i]);
	//				cout<<(*it)<<" ";
	//				cout<<(*--it)<<"\n";
	//				cout<<(*--it)<<"\n";
					if(*(--it)!=a[i-1]){
						pn;fl=1;break;
					}
				}
				else {
					it=p.upper_bound(a[i]);
					if(*(it)!=a[i-1]){
						pn;fl=1;break;
					}
				}
			}
			if(p.find(a[i])==p.end())p.insert(a[i]);//,cout<<a[i]<<"++\n";
//			cout<<i<<"\n";
		}
		if(!fl)py;
	}
}