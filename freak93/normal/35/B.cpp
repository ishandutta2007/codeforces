#include<fstream>
#include<string>
#include<set>
#include<map>

using namespace std;

const char iname[]="input.txt";
const char oname[]="output.txt";

ifstream f(iname);
ofstream g(oname);

set<int> S;
map<string,int> M;

int n,m,k,i,t,x,y;
string s;

int main()
{
	f>>n>>m>>k;
	for(i=1;i<=n*m;++i)
		S.insert(i);
	while(k--)
	{
		f>>t;
		if(t==1)
		{
			f>>x>>y;
			x=(x-1)*m+y;
            if(S.lower_bound(x)!=S.end())
				y=*S.lower_bound(x),S.erase(y);
			else
				y=0;
			f>>s;
			M[s]=y;
			continue;
		}
		f>>s;
		if(M[s]>0&&M[s]<=n*m)
			x=M[s],g<<(x-1)/m+1<<" "<<(x-1)%m+1<<"\n",M[s]=0,S.insert(x);
		else
			g<<"-1 -1\n";
	}
}