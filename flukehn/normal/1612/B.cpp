#include<bits/stdc++.h>
using namespace std;
const int N=1e5+11;
int n,a,b;
int p[N];
void work(){
	#define GG {cout<<-1<<"\n";return;}
	cin>>n>>a>>b;
	vector<int> u,v,w;
	for(int i=1;i<=n;++i)
		if(i<a){
			if(i>b)GG;
			v.push_back(i);
		}else if(i==a)u.push_back(i);
		else if(i==b)v.push_back(i);
		else if(i>b){
			u.push_back(i);
		}else{
			w.push_back(i);
		}
	if(u.size()>n/2||v.size()>n/2)GG;
	int tot=0;
	for(int i:u)p[++tot]=i;
	for(int i:w)p[++tot]=i;
	for(int i:v)p[++tot]=i;
	for(int i=1;i<=n;++i)cout<<p[i]<<" \n"[i==n];
}
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	cin>>t;
	while(t--)work();
}