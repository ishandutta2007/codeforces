#include <iostream>
using namespace std;

int main()
{
	int a[1010],b[1010],n,ans=0,cnt=1;
	
	cin >> n;
	for (int i=0;i<n;i++) cin >> a[i] >> b[i];
	for (int i=0;i<n;i++)
		for (int j=i+1;j<n;j++)
			if (b[j]>b[i] || (b[j]==b[i] && a[j]>a[i]))
				swap(b[i],b[j]), swap(a[i],a[j]);
	
	for (int i=0;cnt && i<n;i++) ans+=a[i], cnt+=b[i]-1;
	cout << ans << endl;
}