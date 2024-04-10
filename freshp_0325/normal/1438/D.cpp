#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
	node(int A=0,int B=0,int C=0){a=A,b=B,c=C;}
};
int n,a[100005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)	scanf("%d",&a[i]);
	vector<node> P;
	if(n&1)
	{
		puts("YES");
		for(int i=1;i<=n;i+=2)
		{
			P.push_back(node(i,i+1,i+2));
		}
		P.pop_back();
		for(int i=1;i<=n;i+=2)
		{
			P.push_back(node(i,i+1,n));
		}
		P.pop_back();
		printf("%d\n",int(P.size()));
		for(auto st:P)	printf("%d %d %d\n",st.a,st.b,st.c);
	}
	else
	{
		int xs=0;
		for(int i=1;i<=n;++i)	xs^=a[i];
		if(xs)	return 0&puts("NO");
		puts("YES");
		--n;
		for(int i=1;i<=n;i+=2)
		{
			P.push_back(node(i,i+1,i+2));
		}
		P.pop_back();
		for(int i=1;i<=n;i+=2)
		{
			P.push_back(node(i,i+1,n));
		}
		P.pop_back();
		printf("%d\n",int(P.size()));
		for(auto st:P)	printf("%d %d %d\n",st.a,st.b,st.c);
	}
	return 0;
}