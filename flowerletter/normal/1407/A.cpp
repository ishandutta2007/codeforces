#include <iostream>
#include <vector>
using namespace std;
int a[1005];
vector <int> ans;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		ans.clear();
		int n;
		cin >> n;
		for(int i=1;i<=n;i++)
			cin >> a[i];
		for(int i=1;i<=n;i+=2)
		{
			if(a[i]!=a[i+1]) ans.push_back(0);
			else ans.push_back(a[i]),ans.push_back(a[i+1]);
		}
		cout << ans.size() << "\n";
		for(auto x:ans) cout << x << " ";
		puts("");
	}
	return 0;
}