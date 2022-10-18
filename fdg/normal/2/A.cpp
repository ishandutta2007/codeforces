#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;


map <string,int> f;
vector <pair<string,int>> v;
vector <string> s;

int main()
{
	long an=-1,kol=0,cur,n;
	string aname="",name;
	cin >> n;
	vector <bool> d(n,0);
	for(int i=0;i<n;i++)
	{
		cin >> name >> cur;
		s.push_back(name);
		v.push_back(make_pair(name,cur));
		if (f.count(name))
			f[name]+=cur;
		else
			f[name]=cur;
	}
	for(int i=0;i<s.size();i++)
	{
		if (f[s[i]]>an) an=f[s[i]];
	}
	for(int i=0;i<s.size();i++)
		if (f[s[i]]==an) d[i]=1;
	f.clear();
	for(int i=0;i<n;i++)
	{
		if (f.count(v[i].first))
			f[v[i].first]+=v[i].second;
		else
			f[v[i].first]=v[i].second;
		if (d[i]&&f[v[i].first]>=an)
		{
			aname=v[i].first;
			break;
		}
	}
	cout << aname << endl;
	return 0;
}

/*#include <fstream>

using namespace std;

int main ()
{
	int v1=0, v2=0;
	ifstream dat1("input1.txt");
	ifstream dat2("input2.txt");
	ofstream sol("output.txt");
	dat1 >> v1;
	dat2 >> v2;
	while((!dat1.eof())||(!dat2.eof()))
	{
		if (v1==v2) sol << v1 << "	";
		if (v1<v2)
			if (!dat1.eof()) dat1 >> v1;
			else dat2 >> v2;
		else
			if (!dat2.eof())dat2 >> v2;
			else dat1 >>v1;
	}
	if (v1==v2) sol << v1 << "	";
	return 0;
}*/


/*#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void Pos(char *mas)
{
	char ans[100]={0};
	int i=0,j=strlen(mas)-1;
	while(mas[i]>='A'&&mas[i]<='Z') i++;
	while(mas[j]>='0'&&mas[j]<='9') j--;
	long row=0,col=0;
	if (j+1==i)
	{
		j++;
		while(mas[j]>='0'&&mas[j]<='9')
		{
			row*=10;
			row+=mas[j]-'0';
			j++;
		}
		for(j=0;j<i;j++)
		{
			col*=26;
			col+=mas[j]-'A'+1;
		}
		ans[0]='R';
		char mas2[100]={0};
		ltoa(row,mas2,10);
		strcat(ans,mas2);
		ans[strlen(ans)]='C';
		char mas1[100]={0};
		ltoa(col,mas1,10);
		strcat(ans,mas1);
	}
	else
	{
		i=1;
		while(mas[i]>='0'&&mas[i]<='9')
		{
			row*=10;
			row+=mas[i]-'0';
			i++;
		}
		i++;
		while(mas[i]>='0'&&mas[i]<='9')
		{
			col*=10;
			col+=mas[i]-'0';
			i++;
		}
		char mas2[100]={0};
		vector <long> nums;
		nums.push_back(0);
		for(int t=1;t<=col;t++)
		{
			
		}
		strcat(ans,mas2);
		char mas1[100]={0};
		ltoa(702,mas1,26);
		cout << mas1 << endl;
		strcat(ans,mas1);
	}
	cout << ans << endl;
}

int main()
{
	long n,i;
	char mas[100]={0};
	cin >> n;
	for(i=0;i<n;i++)
	{
		cin >> mas;
		Pos(mas);
	}
	return 0;
}*/