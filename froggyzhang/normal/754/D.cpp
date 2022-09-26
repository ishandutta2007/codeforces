#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
#define N 300010
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
struct node{
	int l,r,id;
	bool operator <(const node y)const{
		return l<y.l;
	}
}a[N];
int n,k;
priority_queue<int,vector<int>,greater<int> >q;
int main(){
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	n=read();k=read();
	for(int i=1;i<=n;i++){
		a[i].l=read();a[i].r=read();
		a[i].id=i; 
	}
	sort(a+1,a+n+1);
	int len=0,l=0,r=0;
	for(int i=1;i<=n;i++){
		q.push(a[i].r);
		if(q.size()>k)q.pop();
		if(q.size()==k){
			int now=q.top()-a[i].l+1;
			if(now>len){
				len=now;
				l=a[i].l;
				r=q.top();
			}
		}
	}
	cout<<len<<endl;
	if(!len){
		for(int i=1;i<=k;i++){
			cout<<i<<" ";
		}
	}
	else{
		for(int i=1,j=1;i<=n&&j<=k;i++){
			if(a[i].l<=l&&a[i].r>=r){
				cout<<a[i].id<<" ";
				j++;
			}
		}
	}
	return 0;
}