#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<set>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
int f[310000];
long long c[310000];
int segtree[1048576];
int query(int a,int b,int c,int d,int e){
	if(d<a||b<c)return 0;
	if(c<=a&&b<=d)return segtree[e];
	return max(query(a,(a+b)/2,c,d,e*2),query((a+b)/2+1,b,c,d,e*2+1));
}
void update(int a,int b){
	a+=524288;
	segtree[a]=b;
	a/=2;
	while(a){
		segtree[a]=max(segtree[a*2],segtree[a*2+1]);
		a/=2;
	}
}
set<pair<pair<int,int>,int> >S;
set<pair<int,int> >T;
set<pair<int,int> >Tinv;
typedef set<pair<pair<int,int>,int> >::iterator wolf;
inline int sig(long long a){
	if(a<0)return -1;
	if(a==0)return 0;
	return 1;
}
int n;
void add(int a,int b){
	int sc=sig(c[a]);
	int tc=sig(c[a]+b);
	c[a]+=b;
	if(sc==tc)return;
	wolf it=S.upper_bound(make_pair(make_pair(a,mod),0));
	it--;
	pair<pair<int,int>,int> p=(*it);
	if(p.first.first<a)S.insert(make_pair(make_pair(p.first.first,a),sc));
	S.insert(make_pair(make_pair(a,a+1),tc));
	if(a+1<p.first.second)S.insert(make_pair(make_pair(a+1,p.first.second),sc));
	S.erase(p);

	wolf it2=S.upper_bound(make_pair(make_pair(p.first.first-1,mod),0));
	if(it2!=S.begin())it2--;
	if(it2!=S.begin())it2--;
	

	vector<pair<pair<int,int>,int> >que;
	vector<pair<int,int> > del2;

	for(;it2!=S.end()&&(*it2).first.first<=a+1;it2++){
		que.push_back(*it2);
	}
	int last=0;
	int len=0;
	int col=-2;
	vector<pair<pair<int,int>,int> >del;
	for(int i=0;i<que.size();i++){
		update(que[i].first.first,0);
		if(que[i].second!=col){
			if(col!=-2&&len>1){
				S.insert(make_pair(make_pair(last,que[i].first.first),col));
				for(int j=0;j<del.size();j++)S.erase(del[j]);
			}
			del.clear();
			len=0;
			last=que[i].first.first;
			col=que[i].second;
		}
		del.push_back(que[i]);
		len++;
	}
	if(len>1){
		S.insert(make_pair(make_pair(last,que[que.size()-1].first.second),col));
		for(int j=0;j<del.size();j++)S.erase(del[j]);
	}
	
	wolf it4=S.lower_bound(make_pair(make_pair(que[0].first.first,0),-mod));
	for(;it4!=S.end()&&(*it4).first.first<=a+1;it4++){
		pair<pair<int,int>,int>  d=(*it4);
		if(d.second==0)continue;
		int le=d.first.second-d.first.first;
		if(d.second==1){
			it4++;
			if(d.first.second<n-1&&(*it4).second==-1)le+=(*it4).first.second-(*it4).first.first;
			it4--;
		}
//		T.insert(make_pair(le,d.first.first));
//		Tinv.insert(make_pair(d.first.first,le));
		update(d.first.first,le);
	}
//	for(wolf i=S.begin();i!=S.end();i++)printf("%d %d: %d\n",(*i).first.first,(*i).first.second,(*i).second);
	//for(int i=0;i<n;i++)printf("%d ",segtree[524288+i]);
	//printf("\n");
}

int main(){
	int a;scanf("%d",&a);
	n=a;
	for(int i=0;i<a;i++)scanf("%d",f+i);
	if(a==1){
		int q;scanf("%d",&q);
		while(q--)printf("1\n");return 0;
	}
	for(int i=0;i<a-1;i++)c[i]=f[i+1]-f[i];
	int len=0;
	int cur=-2;
	for(int i=0;i<a-1;i++){
		int v=sig(c[i]);
		if(v!=cur){
			if(len)S.insert(make_pair(make_pair(i-len,i),cur));
			len=0;cur=v;
		}
		len++;
	}
	S.insert(make_pair(make_pair(a-1-len,a-1),cur));
	for(wolf it=S.begin();it!=S.end();it++){
		if((*it).second==0)continue;
		if((*it).second==1){
			int le=(*it).first.second-(*it).first.first;
			wolf tmp=it;
			tmp++;
			if(tmp!=S.end()&&(*tmp).second==-1)le+=(*tmp).first.second-(*tmp).first.first;
	//		T.insert(make_pair(le,(*it).first.first));
	//		Tinv.insert(make_pair((*it).first.first,le));
			update((*it).first.first,le);
		}else{
	//		T.insert(make_pair((*it).first.second-(*it).first.first,(*it).first.first));
	//		Tinv.insert(make_pair((*it).first.first,(*it).first.second-(*it).first.first));	
			update((*it).first.first,(*it).first.second-(*it).first.first);
		}
	}
	int Q;scanf("%d",&Q);
	while(Q--){
		int p,q,r;scanf("%d%d%d",&p,&q,&r);
		p--;
		if(p>=1)add(p-1,r);
		if(q<a)add(q-1,-r);
		printf("%d\n",segtree[1]+1);
	}
}