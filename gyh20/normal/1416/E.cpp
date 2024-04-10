#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
struct node{
	int l,r;
	bool operator <(const node A)const{return l==A.l?r<A.r:l<A.l;}
};
set<node>S;
set<node>::iterator it,it1;
int n,m,tg1,tg2,t,a[500002],ans;
signed main(){
	t=read();
	while(t--){
		n=read();
		for(re int i=1;i<=n;++i)a[i]=read();
		S.clear(),tg1=1,tg2=ans=0;
		if(a[1]&1)S.insert((node){1,a[1]-1}),++ans;
		else S.insert((node){a[1]>>1,a[1]>>1});
		for(re int i=2;i<=n;++i){
			if(tg1>0){
				if(a[i]%2==0){
					it=S.lower_bound((node){(a[i]>>1)-tg2,(int)1e18});
					if(it!=S.begin()){
						--it;
						if(it->r>=(a[i]>>1)-tg2){
							S.clear(),tg1=1,tg2=0;
							S.insert((node){a[i]>>1,a[i]>>1});
							continue;
						}
					}
				}
				it=--S.end();
				while(S.size()){
					if(it->r+tg2<a[i])break;
					if(it->l+tg2>=a[i]){
						it1=it;
						if(it!=S.begin())--it;
						S.erase(it1);
						continue;
					}
					re node tmp=*it;
					S.erase(tmp);
					tmp.r=a[i]-tg2-1;
					S.insert(tmp);
					break;
				}
				if(S.size())tg1=-tg1,tg2=-tg2,tg2+=a[i],++ans;
				else if(a[i]%2==1)tg1=1,tg2=0,S.insert((node){1,a[i]-1}),ans+=2;
				else S.clear(),tg1=1,tg2=0,++ans;
			}
			else{
				if(a[i]%2==0){
					it=S.lower_bound((node){-((a[i]>>1)-tg2),(int)1e18});
					if(it!=S.begin()){
						--it;
						if(it->r>=-((a[i]>>1)-tg2)){
							S.clear(),tg1=1,tg2=0;
							S.insert((node){a[i]>>1,a[i]>>1});
							continue;
						}
					}
				}
				it=S.begin();
				while(S.size()){
					if(-it->l+tg2<a[i])break;
					if(-it->r+tg2>=a[i]){
						it1=it,++it;
						S.erase(it1);
						continue;
					}
					re node tmp=*it;
					S.erase(tmp);
					tmp.l=-(a[i]-tg2-1);
					S.insert(tmp);
					break;
				}
				if(S.size())tg1=-tg1,tg2=-tg2,tg2+=a[i],++ans;
				else if(a[i]%2==1)tg1=1,tg2=0,S.insert((node){1,a[i]-1}),ans+=2;
				else S.clear(),tg1=1,tg2=0,++ans;
			}
			if(a[i]%2==0)S.insert((node){tg1*((a[i]>>1)-tg2),tg1*((a[i]>>1)-tg2)});
		}printf("%lld\n",1+ans);
	}
	
}