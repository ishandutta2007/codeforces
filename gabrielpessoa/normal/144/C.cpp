#include <bits/stdc++.h>
using namespace std;

const int SIZE = 105;

int qnt[30];
int qntP[30];
int resposta = 0;

string s;
string p;
int qntInterrogacao;

void check() {
	int interrogacoesNecessarias = 0;
	for(int i = 0; i <= 'z' - 'a'; i++) {
		if(qnt[i] > qntP[i]) return;
		interrogacoesNecessarias += qntP[i] - qnt[i];
	}
	if(interrogacoesNecessarias == qntInterrogacao) {
		resposta++;
	}
}

int main() {
	cin >> s;
	cin >> p;
	if(p.length() > s.length()) {
		printf("0\n");
		return 0;
	}
	for(int i = 0; i < p.length(); i++) {
		if(s[i] == '?') qntInterrogacao++;
		else qnt[s[i]-'a']++;
		qntP[p[i]-'a']++;
	}
	check();
	for(int i = p.length(); i < s.length(); i++) {
		if(s[i - p.length()] == '?') qntInterrogacao--;
		else qnt[s[i-p.length()]-'a']--;
		if(s[i] == '?') qntInterrogacao++;
		else qnt[s[i]-'a']++;
		check();
	}
	printf("%d\n", resposta);
}