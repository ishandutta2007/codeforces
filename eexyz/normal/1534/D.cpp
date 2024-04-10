#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define N 2005
int d[N];
vector<int>s;
int nn,fa[N],n;
void ask(int x){
	cout<<"? "<<x<<"\n";cout.flush();
	for(int i=1;i<=n;++i)cin>>d[i];
}
void solve(int now,vector<int>nd){
	vector<int>hh;
	int i,c=0,x=0,g,n=nd.size();
	for(i=0;i<n;++i){
		if(d[nd[i]]==1)++c,fa[nd[i]]=now;
		if(d[nd[i]]==2)x=1;
	}
	if(!x)return ;
		for(i=0;i<n-1;++i){
			if(nd[i]==now)swap(nd[i],nd[i+1]);
		}
		nd.pop_back();
	if(c==1){
		for(i=0;i<n-1;++i){
			--d[nd[i]];hh.push_back(nd[i]);
		}
		for(i=0;i<n-1;++i)
			if(!d[nd[i]]){solve(nd[i],hh);return ;}
		return ;
	}
	else{
		int tmp[2005];
		char vst[2005];
		for(i=1;i<=nn;++i)tmp[i]=d[i];
		--n;
		while(n){
			c=0;hh.clear(); 
			for(i=0;i<nd.size();++i){
				if(!vst[nd[i]]&&tmp[nd[i]]==2)x=nd[i];
				if(!vst[nd[i]]&&tmp[nd[i]]==2)++c;
			}
			if(c){
				ask(x);
				for(i=0;i<nd.size();++i){
					if(!vst[nd[i]]&&d[nd[i]]<=tmp[nd[i]]){
						d[nd[i]]=tmp[nd[i]]-1;
						hh.push_back(nd[i]);
						vst[nd[i]]=1;
						--n;
						if(d[nd[i]]==0)g=nd[i];
					}
				}
				solve(g,hh);
			}
			else{
				for(i=0;i<nd.size();++i)if(!vst[nd[i]])fa[nd[i]]=now;
				return ;
			}
			
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;nn=n;
	for(int i=1;i<=n;++i)s.push_back(i);
	ask(1);solve(1,s);cout<<"!\n";
	for(int i=2;i<=n;++i)cout<<fa[i]<<" "<<i<<"\n";
}