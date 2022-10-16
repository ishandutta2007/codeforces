#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000005
int las[N],nxt[N],tt[N],n,q,i,typ,l,Fl,Fr,tot,r,x,vis[N];
set<int>s;
set<int>::iterator it;
int fl(int x){
	if(vis[las[x]])las[x]=fl(las[x]);
	return las[x];
}
int fn(int x){
	if(vis[nxt[x]])nxt[x]=fn(nxt[x]);
	return nxt[x];
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(i=0;i<=n+2;++i)las[i]=i-1,nxt[i]=i+1;
	while(q--){
		cin>>typ;
		if(typ==0){
			cin>>l>>r>>x;
			if(x==0){
				for(i=fl(r+1);i>=l;i=fl(i)){
					vis[i]=1;
				}
			}
			else{
				it=s.lower_bound(l);
				if(it!=s.end()&&tt[(*it)]<=r)continue;
				else{
					while(1){
						it=s.upper_bound(l);
						if(it!=s.begin()){
							--it;
							if(tt[*it]>=r)s.erase(*it);
							else break;
						}
						else break;
					}
	//				cout<<p.first<<" "<<p.second<<"\n";
					s.insert(l);
					tt[l]=r;
				}
			}
		}
		else{
			cin>>x;++tot;
			if(vis[x])cout<<"NO\n";
			else{
				Fl=fl(x);
				Fr=fn(x);
				++Fl;--Fr;
	//			cout<<Fl<<" "<<Fr<<"\n"; 
				it=s.lower_bound(Fl);
				if(it!=s.end()&&tt[*it]<=Fr)cout<<"YES\n";
				else cout<<"N/A\n";
			}
		}
	}
}