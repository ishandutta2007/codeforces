#include<bits/stdc++.h>
using namespace std;
int read(){int x;scanf("%d",&x);return x;}
int is_sub(int a,int b){
	vector<int> p,q;
	while(a)p.push_back(a%10),a/=10;
	while(b)q.push_back(b%10),b/=10;
	int i=0,j=0;
	while(i<p.size()){
		while(j<q.size()&&q[j]!=p[i])j++;
		if(j==q.size())return -1;
		else i++,j++;
	}
	return q.size()-p.size();
}
int main(){
	int n=read(),m=100;
	for(int i=1;i*i<=n;i++)
		if(is_sub(i*i,n)!=-1)
			m=min(m,is_sub(i*i,n));
	if(m==100)printf("-1");
	else printf("%d\n",m);
}