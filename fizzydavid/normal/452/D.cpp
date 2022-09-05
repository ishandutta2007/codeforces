#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
#define pb push_back 
#define mp make_pair
typedef long long ll;
const int INF=1<<28;
const long long LINF=1ll<<61;
int st[10011],k,t1,t2,t3,n1,n2,n3;
int main()
{
	cin>>k>>n1>>n2>>n3>>t1>>t2>>t3;
	for(int i=1;i<=min(min(n1,n2),n3);i++)st[i]=0;
	for(int i=min(min(n1,n2),n3)+1;i<=k;i++)
	{
		int x1,x2,x3;
		x1=(i-n1<1)?0:st[i-n1]+t1;
		x2=(i-n2<1)?0:st[i-n2]+t2;
		x3=(i-n3<1)?0:st[i-n3]+t3;
//		cout<<i<<":"<<x1<<" "<<x2<<" "<<x3<<"=";
		st[i]=max(max(x1,x2),x3);
//		cout<<st[i]<<"\n";
	}
	cout<<st[k]+t1+t2+t3; 
// 	system("pause");
	return 0;
}