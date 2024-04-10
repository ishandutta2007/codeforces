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
string s;
int k;
int main()
{
	cin>>s>>k;
	for(int l=(s.size()+k)/2;l>=1;l--)
	{
//		cout<<"l="<<l;
		for(int i=0;i<s.size()-l+1;i++)
		{
//			cout<<"i="<<i;
			bool ok=1;
			for(int j=i;j<=i+l-1;j++)
			{
				if((j+l<s.size()&&s[j]!=s[j+l])||j+l>=s.size()+k){/*cout<<"j:"<<j<<endl;*/ok=0;break;}
			}
			if(ok==1)
			{
				cout<<max(min(k*2,(int)(s.size()+k)/2*2),l*2);
//				system("pause");
				return 0;
			}
		}
	}
	puts("0");
// 	system("pause");
	return 0;
}