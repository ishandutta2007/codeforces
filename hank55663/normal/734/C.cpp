#include<bits/stdc++.h>
#define pii pair<int,int>
#define x first
#define y second
#define mp(x,y) make_pair((x),(y))
#include<vector>
using namespace std;
bool operator<(const pii a,const int b){
	return a.first<b;
}
long long int a[200005],b[200005];
pii c[200005];
int main(){
	long long int n,m,k,s;
	scanf("%I64d %I64d %I64d",&n,&m,&k);
	long long int x;
	scanf("%I64d %I64d",&x,&s);

	for(int i=0;i<m;i++)
	scanf("%I64d",&a[i]);
	for(int i=0;i<m;i++)
	scanf("%I64d",&b[i]);
	map<int,int > mm;
	for(int i=0;i<k;i++)
	scanf("%d",&c[i].second);
	for(int i=0;i<k;i++)
	scanf("%d",&c[i].first);
	sort(c,c+k);
	for(int i=1;i<k;i++)
	if(c[i].second<c[i-1].second)
	c[i].second=c[i-1].second;
	for(int i=0;i<k;i++)
	mm[c[i].x]=c[i].y;
	long long int ans=x*n;
	//mm.upper_bound(s);
	map<int,int>::iterator it=mm.upper_bound(s);
	if(it!=mm.begin())
	it--,ans-=x*(it->second);
	for(int i=0;i<m;i++){
		int ss=s-b[i];
		it=mm.upper_bound(ss);
		if(it==mm.begin()){
			if(ss>=0)
			ans=min(a[i]*n,ans);
			continue;
		}
		it--;
		ans=min(a[i]*(n-it->second),ans);
	}
	printf("%I64d",ans);
	//b[i]+d[j]<s;
	//a[i]*n-c[j];
	
}