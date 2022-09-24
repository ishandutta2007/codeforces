#include<iostream>
using namespace std;
typedef long long LL;
LL N,H,A,B,Q,T,F,t,f;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>H>>A>>B>>Q;
	while(Q--)
	{
		cin>>T>>F>>t>>f;
		if(T==t)
			cout<<abs(F-f);
		else if(F>=A&&F<=B||f>=A&&f<=B)
			cout<<abs(T-t)+abs(F-f);
		else
			cout<<min(abs(T-t)+abs(F-A)+abs(f-A),abs(T-t)+abs(F-B)+abs(f-B));
		cout<<'\n';
	}
	cout<<endl;
	return 0;
}