#include<bits/stdc++.h>
using namespace std;
map<string,bool>mp;
string r;
bool dp[1001];
string k[118]={"Ac","Al","Am","Sb","Ar","As","At","Ba","Bk","Be","Bi","Bh","B","Br","Cd","Ca","Cf","C","Ce","Cs","Cl","Cr","Co","Cn","Cu","Cm","Ds","Db","Dy","Es","Er","Eu","Fm","Fl","F","Fr","Gd","Ga","Ge","Au","Hf","Hs","He","Ho","H","In","I","Ir","Fe","Kr","La","Lr","Pb","Li","Lv","Lu","Mg","Mn","Mt","Md","Hg","Mo","Mc","Nd","Ne","Np","Ni","Nh","Nb","N","No","Og","Os","O","Pd","P","Pt","Pu","Po","K","Pr","Pm","Pa","Ra","Rn","Re","Rh","Rg","Rb","Ru","Rf","Sm","Sc","Sg","Se","Si","Ag","Na","Sr","S","Ta","Tc","Te","Ts","Tb","Tl","Th","Tm","Sn","Ti","W","U","V","Xe","Yb","Y","Zn","Zr"};
int main(){
	cin >> r;
	r='?'+r;
	string s;
	for(int i=0; i<118 ;i++){
		s=k[i];
		if(s.size()>=2) s[1]-=32;
		mp[s]=true;
	}
	dp[0]=true;
	for(int i=1; i<r.size() ;i++){
		string t="s";
		t[0]=r[i];
		dp[i]|=(mp[t])&dp[i-1];
		if(i==1) continue;
		t="ss";
		t[0]=r[i-1],t[1]=r[i];
		dp[i]|=(mp[t])&dp[i-2];
		
	}
	bool ans=dp[r.size()-1];
	if(ans) cout << "YES\n";
	else cout << "NO\n";
}