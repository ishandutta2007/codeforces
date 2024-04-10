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
#define digit(i) t/pow(i)%10
long long a,tmp,l;
int c;
long long pow(int x)
{
	long long res=1;
	for(int i=0;i<x;i++)res*=10;
	return res;
}
int main()
{
	cin>>a>>l;
	long long t=a;
	for(int i=0;pow(i+1)<=a;i++)
	{
//		cout<<t<<endl;
		c=i;
		if(digit(i)!=9)
		{
			tmp=(digit(i)+1)*pow(i);
			t-=tmp;
		}//cout<<a<<" "<<t<<" "<<l<<endl<<endl;
		if(a-t>l)
		{
			break;
		}
	}
	if(a-t>l)
	{
		t+=tmp;
	}
	cout<<t;
 //	system("pause");
	return 0;
}