#include <iostream>
#include <string>
#include <fstream>

using namespace std;
string s, t;
int a[26], b[26], c[26], ans;
int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	cin >> s >> t;
	for (int i=0; i<s.length(); i++) a[s[i]-'A']++, b[t[i]-'A']++, c[s[i]-'A']++;
	for (int i=0; i<26; i++) if (a[i]>b[i]) ans+=a[i]-b[i];
	for (int i=0; i<s.length(); i++) if (a[s[i]-'A']>b[s[i]-'A']){
		bool t=true;
		c[s[i]-'A']--;
		for (int j=0; j<s[i]-'A'; j++) {
			if (a[j]<b[j]) {
				a[s[i]-'A']--, a[j]++, s[i] = j+'A', t=false;
				break;
			}
		}
		if (c[s[i]-'A']+1<=a[s[i]-'A']-b[s[i]-'A']) for (int j=s[i]-'A'; j<26; j++) if (a[j]<b[j]) {
			a[s[i]-'A']--, a[j]++, s[i]=j+'A'; break;
		}
	}
	cout << ans << endl << s;
	return 0;
}