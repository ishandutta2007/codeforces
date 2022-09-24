#include<bits/stdc++.h>
using namespace std;
int n,m,nn,mm,ans=1e8,up=0,nxt[2005];
struct P{
	int x,y;
}aa[2005],bb[2005],a[2005],b[2005];
struct T{
	int id,x;
	bool operator <(const T t) const {
		return x!=t.x?x<t.x:id<t.id;
	}
};
multiset<int> q;
multiset<T> q2;
void Upd(){
	up++;
	while(q2.size()&&up>=(q2.begin()->x)){
		T tmp=*q2.begin();
		int i=tmp.id;
		q2.erase(q2.begin());
		q.erase(q.find(b[nxt[i]].x-a[i].x+1));
		nxt[i]--;
		if(b[nxt[i]].x<a[i].x)nxt[i]=0;
		if(nxt[i])q2.insert({i,b[nxt[i]].y-a[i].y+1}),q.insert(b[nxt[i]].x-a[i].x+1);
	}
	if(q.size())ans=min(ans,up+*--q.end());
}
int main(){
	cin>>nn>>mm;
	for(int i=1;i<=nn;i++)cin>>aa[i].x>>aa[i].y;
	for(int j=1;j<=mm;j++)cin>>bb[j].x>>bb[j].y;
	sort(aa+1,aa+nn+1,[](P i,P j){return i.x!=j.x?i.x<j.x:i.y<j.y;});
	sort(bb+1,bb+mm+1,[](P i,P j){return i.x!=j.x?i.x<j.x:i.y<j.y;});
	for(int i=nn;i>=1;i--){
		bool f=0;
		for(int j=i-1;j>=1;j--){
			if(aa[i].x>=aa[j].x&&aa[i].y>=aa[j].y)f=1;
		}
		if(!f)a[++n]=aa[i];
	}
	for(int i=1;i<=mm;i++){
		bool f=0;
		for(int j=i+1;j<=mm;j++){
			if(bb[i].x<=bb[j].x&&bb[i].y<=bb[j].y)f=1;
		}
		if(!f)b[++m]=bb[i];
	}
	reverse(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[j].x<a[i].x||b[j].y<a[i].y)continue;
			if(!nxt[i]||b[j].y<b[nxt[i]].y)nxt[i]=j;
		}
		if(nxt[i])q.insert(b[nxt[i]].x-a[i].x+1),q2.insert({i,b[nxt[i]].y-a[i].y+1});
	}
	if(!q.size()){
		cout<<0;
		return 0;
	}
	ans=*--q.end();
	for(int i=0;i<=1e6;i++){
		Upd();
		if(!q.size()){
			ans=min(ans,up);
			break; 
		} 
	}
	cout<<ans;
	return 0;
}