#include<bits/stdc++.h>
using namespace std;
main(){
	int t;
	scanf("%d",&t);
	map<long long int,long long int> m;
	m.clear();
	while(t--){
		int a;
		scanf("%d",&a);
		if(a==1){
			long long int u,v,w;
			scanf("%I64d %I64d %I64d",&u,&v,&w);
			set<long long int> s;
			s.clear();
			long long int b=u;
			while(b){
				s.insert(b);
				b>>=1;
			} 
			while(v){
				if(s.find(v)==s.end()){
					m[v]+=w;
					v>>=1;
				}
				else
				break;
			}
			while(u){
				if(u!=v){
					m[u]+=w;
					u>>=1;
				}
				else
				break;
			}
		}
		else{
			long long int u,v;
			scanf("%I64d %I64d",&u,&v);
			long long int ans=0;
			set<long long int> s;
			s.clear();
			long long int b=u;
			while(b){
				s.insert(b);
				b>>=1;
			} 	
			while(v){
				if(s.find(v)==s.end()){
					ans+=m[v];
					v>>=1;
				}
				else
				break;
			}
			while(u){
				if(u!=v){
					ans+=m[u];
					u>>=1;
				}
				else
				break;
			}
			printf("%I64d\n",ans);
		}
	}
}