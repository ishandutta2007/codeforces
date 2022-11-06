#include<bits/stdc++.h>
using namespace std;
long long n,i,hs;
string s;
map <string,long long> ss;
int main()
{
	cin>>n;
	ss["Tetrahedron"]=4;
	ss["Cube"]=6;
	ss["Octahedron"]=8;
	ss["Dodecahedron"]=12;
	ss["Icosahedron"]=20;
	for(i=1;i<=n;i++)
	{
		cin>>s;
		hs=hs+ss[s];
	}
	cout<<hs<<endl;
}