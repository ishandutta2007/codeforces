#include<bits/stdc++.h> 

#define ll long long

using namespace std;
int main() 
{ 
    int n; string s; cin>>n>>s; string aux="";
    for(int i=0; i<s.length(); i++) {
    	aux+=s[i]; if (aux[aux.length()-2]=='('&&aux[aux.length()-1]==')') aux.erase(aux.length()-2, 2);
	}
	if (aux==""||aux==")(") cout<<"Yes"; else cout<<"No";
}