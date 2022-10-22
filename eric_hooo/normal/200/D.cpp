#include <bits/stdc++.h>
using namespace std;

char buf[100010];
map <string, int> type;
map <string, vector <vector <int> > > fun;
map <string, int> var;

void init(){
	type["T"] = 0, type["int"] = 1, type["string"] = 2, type["double"] = 3;
}

vector <int> Get_type(map <string, int> &mp){
	gets(buf);
	int n = strlen(buf);
	vector <int> res;
	string now;
	for (int i = 0; i < n; i++){
		if (buf[i] == ' ' || buf[i] == '(') continue;
		if (buf[i] == ',' || buf[i] == ')'){
			res.push_back(mp[now]);
			now = "";
			continue;
		}
		now += buf[i];
	}
	return res;
}

string Get_name(){
	char c = getchar();
	string res;
	while (c != '('){
		if (c != ' ') res += c;
		c = getchar(); 
	}
	return res;
}

void Get_fun(){
	scanf("%s", buf);
	string name = Get_name();
	vector <int> v = Get_type(type);
	fun[name].push_back(v);
	return ;
}

void Get_var(){
	scanf("%s", buf);
	string t = buf;
	scanf("%s", buf);
	string name = buf;
	var[name] = type[t];
	return ;
}

int Check(vector <int> a, vector <int> b){
	if (a.size() != b.size()) return 0;
	for (int i = 0; i < a.size(); i++){
		if (a[i] != b[i] && a[i] != 0) return 0;
	}
	return 1;
}

int Count(){
	string name = Get_name();
	if (!fun.count(name)){
		gets(buf);
		return 0;
	}
	vector <vector <int> > t = fun[name];
	vector <int> now = Get_type(var);
	int res = 0;
	for (int i = 0; i < t.size(); i++){
		if (Check(t[i], now)) res++;
	}
	return res;
}

int main(){
	int n, m, k;
	init();
	scanf("%d", &n), gets(buf);
	for (int i = 0; i < n; i++){
		Get_fun();
	}
	scanf("%d", &m), gets(buf);
	for (int i = 0; i < m; i++){
		Get_var();
	}
	scanf("%d", &k), gets(buf);
	for (int i = 0; i < k; i++){
		printf("%d\n", Count());
	}
	return 0;
}