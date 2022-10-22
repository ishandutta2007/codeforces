#include<iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;

const int maxn=35;
const int inf=0x3f3f3f3f;

struct ans
{
	int win,points,other;
};

map<string,int> last;
map<string,int> sum;
map<string,vector<string> >E;
map<string,ans> R;
string s[maxn];
string mat[maxn][maxn][maxn];

int calc(string x)
{
	int rez=0,maxt=0,sumt=0;
	for(int i=0;i<x.size();++i)
    	maxt=max(maxt,x[i]-'a'+1),sumt+=x[i]-'a'+1;
	rez=maxt*sumt+sum[x];
	return rez;
}

ans get_ans(string x)
{
	if(R.find(x)!=R.end())
		return R[x];
	vector<string>::iterator it=E[x].begin(),lit=E[x].end();
	ans rez;rez.win=0;rez.points=-1;rez.other=inf;
	for(;it!=lit;++it)
	{
		ans aux=get_ans(*it);
		if(aux.win>rez.win)
		{
			rez=aux;
			continue;
		}
		if(aux.win<rez.win)
			continue;
		if(aux.points>rez.points)
		{
			rez=aux;
			continue;
		}
		if(aux.points<rez.points)
			continue;
		if(aux.other<rez.other)
			rez=aux;

	}
	ans aux=rez;
	if(rez.points==-1)
		rez.win=1,rez.points=0,rez.other=0;
	else
		rez.win=1-aux.win,rez.points=aux.other,rez.other=aux.points;
	rez.points+=calc(x);
	R[x]=rez;
	return rez;
}

int n,i,j,k;

int main()
{
	cin>>n;
	cin.get();
	for(i=1;i<=n;++i)
		cin>>s[i];
	for(i=1;i<=n;++i)
		for(j=0;j<s[i].size();++j)
			for(k=j;k<s[i].size();++k)
				if(k==j)
					mat[i][j][k]=s[i][j];
				else
					mat[i][j][k]=mat[i][j][k-1]+s[i][k];
	for(i=1;i<=n;++i)
		for(j=0;j<s[i].size();++j)
			for(k=j;k<s[i].size();++k)
			{
				if(last[mat[i][j][k]]!=i)
					last[mat[i][j][k]]=i,++sum[mat[i][j][k]];
				if(j>0)
					E[mat[i][j][k]].push_back(mat[i][j-1][k]);
				if(k+1<s[i].size())
					E[mat[i][j][k]].push_back(mat[i][j][k+1]);
			}
	ans rez;
	rez.win=0;rez.points=-1;rez.other=inf;
	for(i='a';i<='z';++i)
	{
		s[0]=(char)i;
		if(E.find(s[0])!=E.end())
        {
			ans bop=get_ans(s[0]);
			if(bop.win>rez.win)
				rez=bop;
			else
				if(bop.win<rez.win)
					continue;
			if(bop.points>rez.points)
				rez=bop;
			else
				if(bop.points<rez.points)
					continue;
			if(bop.other<rez.other)
				rez=bop;
			else
				continue;
		}
	}
	if(rez.win==1)
		cout<<"First\n";
	else
		cout<<"Second\n";
	cout<<rez.points<<" "<<rez.other;
}