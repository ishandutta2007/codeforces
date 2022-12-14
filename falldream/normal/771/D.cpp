#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#define ll long long
using namespace std;
inline int read()
{
    int  x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

vector<int> v,k,o;
int n;
char st[100];
ll f[77][77][77][2];

int main()
{
	n=read();memset(f,127,sizeof(f));
	scanf("%s",st+1);
	for(int i=1;i<=n;i++)
		if(st[i]=='V') v.push_back(i);
		else if(st[i]=='K')k.push_back(i);
		else o.push_back(i);
	f[0][0][0][0]=0;
	for(int i=0;i<=v.size();i++)
		for(int j=0;j<=k.size();j++)
			for(int l=0;l<=o.size();l++)
				for(int c=0;c<=2;c++)
				{
					if((!i)&&(!c))continue;
					if((!j)&&c==1)continue;
					if((!l)&&c==2)continue;
					int pos,num=0;
					if(!c) pos=v[i-1];
					else if(c==1) pos=k[j-1];
					else pos=o[l-1];//cout<<pos<<endl;
					for(int m=i;m<v.size()&&v[m]<pos;m++)num++;//cout<<num<<endl;
					for(int m=j;m<k.size()&&k[m]<pos;m++)num++;//cout<<num<<endl;
					for(int m=l;m<o.size()&&o[m]<pos;m++)num++;
				//	cout<<num<<endl;
					if(c==0)for(int m=0;m<=1;m++) f[i][j][l][1]=min(f[i][j][l][1],f[i-1][j][l][m]+num);
					if(c==1)for(int m=0;m<=0;m++) f[i][j][l][0]=min(f[i][j][l][0],f[i][j-1][l][m]+num);
					if(c==2)for(int m=0;m<=1;m++) f[i][j][l][0]=min(f[i][j][l][0],f[i][j][l-1][m]+num);
				//	cout<<i<<" "<<j<<" "<<l<<" "<<f[i][j][l][0]<<" "<<f[i][j][l][1]<<endl;
				}
	int a=v.size(),b=k.size(),c=o.size();
	cout<<min(f[a][b][c][0],f[a][b][c][1]);
	return 0;
}