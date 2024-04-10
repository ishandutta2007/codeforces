#include<bits/stdc++.h>
using namespace std;
struct Node{
	int a,b;
};
bool cmp(Node x,Node y)
{
	if(x.b>=0&&y.b>=0)
		return x.a<y.a;
	
	if(x.b<0&&y.b<0)
		return x.a+x.b>y.a+y.b;
	
	return x.b>=0;
}
int main(){
	int n,m;
	cin>>n>>m;
	Node p[n];
	
	for(int i=0;i<n;i++)
	    cin>>p[i].a>>p[i].b;
	
	sort(p,p+n,cmp);
	for(int i=0;i<n;i++)
	{
		if(m<p[i].a)
		{
			puts("NO");
			return 0;
		}
		m+=p[i].b;
	}
	if(m<0)
		cout<<"NO";
	else
        cout<<"YES";
	return 0;
}