#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s,x;

map<int,string> its;
map<string,int> sti;
map<int,string> output;
vector<int> ord;

int id=0;
char gang=(char)92;

inline string operate(string x)
{
	int end = 0;
	for (int i = 0; i < x.length(); i++){
		if (x[i] == '}') end = i;
	}
	x=x.substr(5, end - 5 + 1);
	x=(string)"\\"+(string)"bibitem"+x;
	return x;
}

inline int getid(string str)
{
	for(int i=0;i<str.size();i++)
		if(str[i]=='}'){
			str=str.substr(0,i+1);
			break;	
		}
	istringstream ss(str);
	string z;
	ss >> z;
	return sti[z];
}

inline void outpt()
{
	cout<<"Incorrect"<<endl;
	cout<<"\\begin{thebibliography}{99}"<<endl;
	for(int i=0;i<ord.size();i++)
		cout<<output[i]<<endl;
	cout<<"\\end{thebibliography}"<<endl;
	return;
}

char buf[100010];

int main(){
	while(gets(buf)){
		s = buf;
		if(s[0]=='\\' && s[1] == 'b')
			break;
		for(int i=0;i<s.size();i++)
			if(s[i]=='.'||s[i]==','||s[i]==39)
				s[i]=' ';
		istringstream ss(s);
		while(ss >> x){
			if(x[0]==92&&'a'<=x[6]&&x[6]<='z'){
				x=operate(x);
				its[id]=x;
				sti[x]=id++;
			}
		}
	}
	while(gets(buf)){
		s = buf;
		if(s[1]=='e'&&s[2]=='n'&&s[3]=='d')
			break;
		if(!s.size()) continue;
		int here=getid(s);
		output[here]=s;
		ord.push_back(here);
	}
	
	for(int i=0;i<ord.size();i++){
		if(ord[i]!=i){
			outpt();
			return 0;
		}
	}
	printf("Correct\n");
	return 0;
}
/*
The most famous characters of Pushkins works are Onegin \cite{onegin},
Dubrovsky \cite{dubrovsky} and Tsar Saltan \cite{saltan}.
\begin{thebibliography}{99}
\bibitem{saltan} A.S.Pushkin. The Tale of Tsar Saltan. 1832.
\bibitem{onegin} A.S.Pushkin. Eugene Onegin. 1831.
\bibitem{dubrovsky} A.S.Pushkin. Dubrovsky. 1841.
\end{thebibliography}

*/