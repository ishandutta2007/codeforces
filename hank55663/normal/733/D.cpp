#include<bits/stdc++.h>
#define pb(x) push_back(x)
#define pii pair<int,int>
#define mp(x,y) make_pair((x),(y))
#define x first
#define y second  
using namespace std;
typedef long long ll;
struct stone{
	int a,b,c,i;
	void sort(){
		if(c>a)
		swap(c,a);
		if(b>a)
		swap(b,a);
		if(c>b)
		swap(b,c);
	}
};
bool cmp1(const stone &a,const stone &b){
	if(a.a!=b.a)
	return a.a<b.a;
	if(a.b!=b.b)
	return a.b<b.b;
	return a.c<b.c;
}
bool cmp2(const stone &a,const stone &b){
	if(a.b!=b.b)
	return a.b<b.b;
	if(a.c!=b.c)
	return a.c<b.c;
	return a.a<b.a;
}
bool cmp3(const stone &a,const stone &b){
	if(a.a!=b.a)
	return a.a<b.a;
	if(a.c!=b.c)
	return a.c<b.c;
	return a.b<b.b;
}
stone s[100005];
int main(){
	int n;
	scanf("%d",&n);
	int ans1=0,ans1n=0;
	for(int i=0;i<n;i++){
		scanf("%d %d %d",&s[i].a,&s[i].b,&s[i].c);
		s[i].sort();
		s[i].i=i+1;
		int k=ans1;
		ans1=max(ans1,min(min(s[i].a,s[i].b),s[i].c));
		if(k!=ans1)
		ans1n=i+1;
	}
	sort(s,s+n,cmp1);
	int ans2=0;
	pii ans2n;
	for(int i=0;i<n-1;i++){
		if(s[i].a==s[i+1].a&&s[i].b==s[i+1].b){
			int k=ans2;
			ans2=max(ans2,min(min(s[i].a,s[i].b),s[i].c+s[i+1].c));
			if(k!=ans2)
			ans2n=mp(min(s[i].i,s[i+1].i),max(s[i].i,s[i+1].i));
		}
	}
	sort(s,s+n,cmp2);
	for(int i=0;i<n-1;i++){
		if(s[i].c==s[i+1].c&&s[i].b==s[i+1].b){
			int k=ans2;
			ans2=max(ans2,min(min(s[i].a+s[i+1].a,s[i].b),s[i].c));
			if(k!=ans2)
			ans2n=mp(min(s[i].i,s[i+1].i),max(s[i].i,s[i+1].i));
		}
	}
	sort(s,s+n,cmp3);
	for(int i=0;i<n-1;i++){
		if(s[i].c==s[i+1].c&&s[i].a==s[i+1].a){
			int k=ans2;
			ans2=max(ans2,min(min(s[i].a,s[i].b+s[i+1].b),s[i].c));
			if(k!=ans2)
			ans2n=mp(min(s[i].i,s[i+1].i),max(s[i].i,s[i+1].i));
		}
	}
	if(ans1>=ans2)
	printf("1\n%d\n",ans1n);
	else
	printf("2\n%d %d\n",ans2n.first,ans2n.second);
}