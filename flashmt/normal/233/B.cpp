#include <iostream>
#include <cmath>
using namespace std;

int sum(long long s)
{
	return s?sum(s/10)+s%10:0;
}

int main()
{
	long long n,ans=1LL<<60;
	cin >> n;
	for (int s=18*9;s;s--)
	{
		long long delta=1LL*s*s+4*n,sr,x;
		if (delta<0) continue;
		sr=sqrt(delta);
		if (sr*sr<delta) continue;
		if (sr%2!=s%2) continue;
		x=(-s+sr)/2;
		if (x>0 && sum(x)==s) ans=min(ans,x);
	}
	
	cout << (ans>>60&1?-1:ans) << endl;
}