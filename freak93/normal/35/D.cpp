#include<fstream>
#include<algorithm>

using namespace std;

const char iname[]="input.txt";
const char oname[]="output.txt";

ifstream f(iname);
ofstream g(oname);

int n,x,a[500],b[500],i,j;

int main()
{
	f>>n>>x;
	for(i=1;i<=n;++i)
		f>>a[i],a[i]*=(n-i+1);
	sort(a+1,a+n+1);
	for(i=1;a[i]<=x&&i<=n;++i)
		x-=a[i];
	g<<i-1;
}