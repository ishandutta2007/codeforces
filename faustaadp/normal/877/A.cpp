#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
using namespace std;
string s;
ll h;
int main()
{
	cin>>s;
	s=s+"000000000000000";
	//cout<<s<<"\n";
	h=0;
	for(int i=0;i<s.length()-6;i++)
	{
	//	cout<<h<<"\n";
		if(s.substr(i,5)=="Danil")
			h++;
		if(s.substr(i,4)=="Olya")
			h++;
		if(s.substr(i,5)=="Slava")
			h++;
		if(s.substr(i,3)=="Ann")
			h++;
		if(s.substr(i,6)=="Nikita")
			h++;
	}
	/*if(0<=s.find("Danil")&&s.find("Danil")<s.length())
		h++;
	if(0<=s.find("Olya")&&s.find("Olya")<s.length())
		h++;
	if(0<=s.find("Slava")&&s.find("Slava")<s.length())
		h++;
	if(0<=s.find("Ann")&&s.find("Ann")<s.length())
		h++;
	if(0<=s.find("Nikita")&&s.find("Nikita")<s.length())
		h++;*/
	if(h==1)
		cout<<"YES\n";
	else
		cout<<"NO\n";
}