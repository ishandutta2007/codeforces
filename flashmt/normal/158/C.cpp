#include <iostream>
#include <string>
#include <vector>
using namespace std;

int total=1,p[100100];
vector <int> a[100100];
string name[100100];

string get(int x)
{
	return (p[x]?get(p[x]):"")+name[x]+"/";
}

int find(int x,string curName)
{
	if (curName=="..") return p[x];
	for (int i=0;i<int(a[x].size());i++)
		if (name[a[x][i]]==curName) return a[x][i];
	a[x].push_back(++total);
	name[total]=curName;
	p[total]=x;
	return total;
}

int main()
{
	int n,cur=1;
	name[1]="";
	string command,directory;
	cin >> n;
	while (n--)
	{
		cin >> command;
		
		if (command=="cd")
		{
		
			cin >> directory;
			
			if (directory[0]=='/') 
			{
				cur=1; directory.erase(0,1);
			}
				
			while (!directory.empty())
			{
				string curName="";
				while (!directory.empty())
				{
					char ch=directory[0];
					directory.erase(0,1);
					if (ch=='/') break;
					curName+=ch;
				}
				cur=find(cur,curName);
		
			}
		}
		
		else cout << get(cur) << endl;
	}	
}