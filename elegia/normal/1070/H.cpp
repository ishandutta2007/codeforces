#include <iostream>
#include <map>

using namespace std;

struct Node {
	int x;
	int i;
	map<char, Node*> child;
};

void insert(Node* p, const string& s, int i)
{
	for(int j = 0; j < s.length(); j++) {
		if(p->child[s[j]] == NULL)
			p->child[s[j]] = new Node();
		p = p->child[s[j]];
		
		if (p->i != i)
			p->x++;
		p->i = i;
	}
}

Node* query(Node* p, const string& s)
{
	for(int i = 0; i < s.length(); i++) {
		p = p->child[s[i]];
		
		if(p == NULL)
			return p;
	}
	
	return p;
}

int main()
{
	int N;
	cin >> N;
	
	Node* p = new Node();
	string name[10005];
	for(int i = 1; i <= N; i++) {
		string s;
		cin >> s;
		
		for(int j = 0; j < s.length(); j++)
			insert(p, s.substr(j), i);
		
		name[i] = s;
	}
	
	int Q;
	cin >> Q;
	
	for(int _ = 1; _ <= Q; _++) {
		string s;
		cin >> s;
		
		Node* q = query(p, s);
		
		if(q == NULL)
			cout << "0 -" << endl;
		else
			cout << q->x << ' ' << name[q->i] << endl;
	}
}