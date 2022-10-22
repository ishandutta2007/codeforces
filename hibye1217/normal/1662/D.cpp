#import<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
LL n,t,x;
string a,b,sa,sb;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(cin>>t;t--;)
	{
		cin>>a>>b;
		sa=sb="";
		x=0;
		for(auto &c:a)
		{
			if(c=='B')x^=1;
			else if(sa.size()&&sa.back()==c)sa.pop_back();
			else sa.push_back(c);
		}
		for(auto &c:b)
		{
			if(c=='B')x^=1;
			else if(sb.size()&&sb.back()==c)sb.pop_back();
			else sb.push_back(c);
		}
		if(!x&&sa==sb)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}