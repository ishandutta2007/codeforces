// School Team Contest #1
// Problem G -- Inverse Function
#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int MOD = 32768;

extern int getValue(int n);
extern int parseFunction(string body, int n);
extern int parseOperatorSequence(string body, int n);
extern int parseOperator(string body, int n);
extern int parseLogicalExpr(string body, int n);
extern int parseArithmExpr(string body, int n);
extern int parseSum(string body, int n);
extern int parseProduct(string body, int n);
extern int parseMultiplier(string body, int n);
extern int parseNumber(string body, int n);

int result[MOD];


int getValue(int n)
{
	return result[n];
}

int parseFunction(string body, int n)
{
	return parseOperatorSequence(body.substr(11, body.size() - 12), n);
}

int parseOperatorSequence(string body, int n)
{
//	cout << body << endl;
	for(int i = 0; i < body.size(); ++ i){
		if(body[i] == ';'){
			int tmp = parseOperator(body.substr(0, i), n);
			if(tmp != -1){
				return tmp;
			}
			return parseOperatorSequence(body.substr(i + 1, body.size() - (i + 1)), n);
		}
	}
}

int parseOperator(string body, int n)
{
//	cout << body << endl;
	int bracket = 0;
	if(body[0] == 'i'){
		for(int i = 0; i < body.size(); ++ i){
			if(body[i] == ')'){
				bracket += 1;
			}
			if(body[i] == '('){
				bracket -= 1;
			}			
			if(bracket == 0 && body[i] == ')'){
				if(parseLogicalExpr(body.substr(3, i - 3), n)){
					return parseOperator(body.substr(i + 1, body.size() - (i + 1)), n);
				}
				return -1;
			}
		}
	}else{
		return parseArithmExpr(body.substr(6, body.size() - 6), n);
	}
}

int parseLogicalExpr(string body, int n)
{
//	cout << body << endl;
	for(int i = 0; i < body.size(); ++ i){
		if(body[i] == '<'){
			return parseArithmExpr(body.substr(0, i), n) < parseArithmExpr(body.substr(i + 1, body.size() - (i + 1)), n);
		}
		if(body[i] == '>'){
			return parseArithmExpr(body.substr(0, i), n) > parseArithmExpr(body.substr(i + 1, body.size() - (i + 1)), n);
		}
		if(body[i] == '='){
			return parseArithmExpr(body.substr(0, i), n) == parseArithmExpr(body.substr(i + 2, body.size() - (i + 2)), n);
		}
	}
}

int parseArithmExpr(string body, int n)
{
//	cout << body << endl;
	return parseSum(body, n);
}

int parseSum(string body, int n)
{
//	cout << body << endl;
	int bracket = 0;
	for(int i = body.size() - 1; i > -1; -- i){
		if(body[i] == ')'){
			bracket += 1;
		}
		if(body[i] == '('){
			bracket -= 1;
		}
		if(bracket == 0 && body[i] == '+'){
			return (parseSum(body.substr(0, i), n) + parseProduct(body.substr(i + 1, body.size() - (i + 1)), n)) % MOD;	
		}
		if(bracket == 0 && body[i] == '-'){
			return ((parseSum(body.substr(0, i), n) - parseProduct(body.substr(i + 1, body.size() - (i + 1)), n)) % MOD + MOD) % MOD;
		}
	}
	return parseProduct(body, n);
}

int parseProduct(string body, int n)
{
//	cout << body << endl;
	int bracket = 0;
	for(int i = body.size() - 1; i > -1; -- i){
		if(body[i] == ')'){
			bracket += 1;
		}
		if(body[i] == '('){
			bracket -= 1;
		}
		if(bracket == 0 && body[i] == '*'){
			return (parseProduct(body.substr(0, i), n) * parseMultiplier(body.substr(i + 1, body.size() - (i + 1)), n)) % MOD;
		}
		if(bracket == 0 && body[i] == '/'){
			return parseProduct(body.substr(0, i), n) / parseMultiplier(body.substr(i + 1, body.size() - (i + 1)), n);
		}
	}
	return parseMultiplier(body, n);
}

int parseMultiplier(string body, int n)
{
//	cout << body << endl;
	if(body[0] == 'n'){
		return n;
	}else if(body[0] == 'f'){
		return getValue(parseArithmExpr(body.substr(2, body.size() - 3), n));
	}else{
		return parseNumber(body, n);
	}
}

int parseNumber(string body, int n)
{
//	cout << body << endl;
	int temp;
	sscanf(body.c_str(), "%d", &temp);
	return temp;
}

int main()
{
	int value;
	string function;	
	cin >> value;
	{
		string buffer;
		while(cin >> buffer){
			for(int i = 0; i < buffer.size(); ++ i){
				if(buffer[i] != ' '){
					function += buffer[i];
				}
			}
		}
	}
	memset(result, -1, sizeof(result));
	for(int i = 0; i < MOD; ++ i){
		result[i] = parseFunction(function, i);
	}
	for(int i = MOD - 1; i > -1; -- i){
		if(getValue(i) == value){
			cout << i << endl;
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}