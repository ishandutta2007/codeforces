#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		string a;
		cin >> a;
		int now=a.size()+'a'-1,ans=0;
		while(now>='a')
		{
			if(a[0]==now) a=a.substr(1);
			else if(a.back()==now) a=a.substr(0,a.size()-1);
			else
			{
				ans=1;
				break;
			}
			--now;
		}
		if(ans) cout << "nO\n";
		else cout << "yEs\n";
	}
	return 0;
}
//