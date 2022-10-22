#include<fstream>
#include<algorithm>

using namespace std;

const char iname[]="input.txt";
const char oname[]="output.txt";

ifstream f(iname);
ofstream g(oname);

int a[10],x,y,i,v;

int main()
{
	f>>v;
	a[v]=1;
	for(i=1;i<=3;++i)
		f>>x>>y,swap(a[x],a[y]);
	for(i=1;i<=3;++i)
		if(a[i]==1)
			g<<i;
}