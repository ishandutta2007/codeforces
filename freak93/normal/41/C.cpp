#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string ans,s;
int i,ok,j,aux;

int main()
{
	cin>>s;
	s+="  ";
	for(i=1;i<s.size()-4;++i)
		if(s[i]=='a'&&s[i+1]=='t')
		{
			string aux;
			aux+=s[0];
			for(j=1;j<i;++j)
				if(s[j]=='d'&&s[j+1]=='o'&&s[j+2]=='t')
					aux+='.',j+=2;
				else
					aux+=s[j];
			aux+='@';
			for(j=i+2;j<s.size()-5;++j)
				if(s[j]=='d'&&s[j+1]=='o'&&s[j+2]=='t')
					aux+='.',j+=2;
				else
					aux+=s[j];
			for(;j<s.size()-2;++j)
				aux+=s[j];
			if(ok==0)
				ans=aux,ok=1;
			else
				if(aux<ans)
					ans=aux;
		}
	cout<<ans;
}