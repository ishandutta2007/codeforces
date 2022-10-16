#include <bits/stdc++.h>

using namespace std;

int parseInt(string&s, int f, int t){
    int ats = 0;
    for(int i = f;i<t;i++){
        ats*=10;
        ats+=s[i]-'0';
    }
    return ats;
}
string parseChars(string&s, int f, int t){
    return s.substr(f,t-f-1);
}

string intToChars(int s){
    string a= "";
    while(s>0){
        s--;
        //cout << s << endl;
        a.push_back((s%26)+'A');
        s/=26;
    }
    reverse(a.begin(), a.end());
    return a;
}

int charsToInt(string a){
    int s=0;
    for(int i=0;i<a.size();i++){
        s*=26;
        s+=a[i]-'A'+1;
    }
    return s;
}

int main () {
	int n;
	cin >> n;
	while(n--){
	    string a;
	    cin >> a;
	    bool skaiciai = false;
	    int c = a.find('C');
	    if(a[0]=='R' and c!=-1){
	        for(int i = 1;i<c;i++){
	            skaiciai = skaiciai or isdigit(a[i]);
	        }
	    }
	    if(skaiciai){
	        cout << intToChars(parseInt(a,c+1,a.size()))<<parseInt(a,1,c);
	    }else{
	        int pos = 0;
	        while(!isdigit(a[pos++]));
	        cout << "R" << parseInt(a,pos-1,a.size());
	        cout << "C" << charsToInt(parseChars(a,0,pos));
	    }
	    cout << endl;
	}

	return 0;
}