#include<bits/stdc++.h>

using namespace std;

using Int = long long;

// alphabet is [OFFSET, OFFSET + SIZE), with sentinel (OFFSET - 1)
template <class T, int SIZE, T OFFSET> struct Depam {
  struct Node {
    // ts[pos, pos + len]: prefix/suffix when created
    // fail: longest proper palindromic prefix/suffix
    // quick[a]: longest proper palindromic prefix/suffix followed/preceded by a
    int len, pos, fail;
    int nxt[SIZE], quick[SIZE];
  };

  // nodes[0]: length 0  (also means null in nxt)
  // nodes[1]: length -1
  // nodes[2, nodesLen): non-empty palindromic substring
  int nodesLen, pre, suf;
  vector<Node> nodes;
  // string is ts[l, r)  (1 <= l <= 1 + nL <= r <= 1 + nL + nR)
  int nL, nR, l, r;
  vector<T> ts;
  // ((~pre)/suf before pushFront/pushBack, parent of created node or -1)
  int historyLen;
  vector<pair<int, int>> history;

  Depam(int nL_, int nR_) : nL(nL_), nR(nR_) {
    nodesLen = 2;
    pre = suf = 0;
    nodes.resize(2 + nL + nR);
    nodes[0].len =  0; nodes[0].pos = 0; nodes[0].fail = 1;
    nodes[1].len = -1; nodes[1].pos = 0; nodes[1].fail = 1;
    memset(nodes[0].nxt, 0, sizeof(nodes[0].nxt));
    memset(nodes[1].nxt, 0, sizeof(nodes[1].nxt));
    for (int a = 0; a < SIZE; ++a) nodes[0].quick[a] = 1;
    for (int a = 0; a < SIZE; ++a) nodes[1].quick[a] = 1;
    l = r = 1 + nL;
    ts.assign(1 + nL + nR + 1, OFFSET - 1);
    historyLen = 0;
    history.resize(nL + nR);
  }
  void pushFront(T t) {
    assert(1 < l);
    const int a = t - OFFSET;
    history[historyLen++] = make_pair(~pre, -1);
    ts[--l] = t;
    if (ts[l + 1 + nodes[pre].len] != t) pre = nodes[pre].quick[a];
    Node &f = nodes[pre];
    if (!f.nxt[a]) {
      history[historyLen - 1].second = pre;
      Node &g = nodes[nodesLen];
      g.len = f.len + 2; g.pos = l; g.fail = nodes[f.quick[a]].nxt[a];
      memset(g.nxt, 0, sizeof(g.nxt));
      memcpy(g.quick, nodes[g.fail].quick, sizeof(g.quick));
      g.quick[ts[l + nodes[g.fail].len] - OFFSET] = g.fail;
      f.nxt[a] = nodesLen++;  // this needs to be after setting g.fail
    }
    if (nodes[pre = f.nxt[a]].len == r - l) suf = pre;
  }
  void pushBack(T t) {
    assert(r < 1 + nL + nR);
    const int a = t - OFFSET;
    history[historyLen++] = make_pair(suf, -1);
    ts[r++] = t;
    if (ts[r - 2 - nodes[suf].len] != t) suf = nodes[suf].quick[a];
    Node &f = nodes[suf];
    if (!f.nxt[a]) {
      history[historyLen - 1].second = suf;
      Node &g = nodes[nodesLen];
      g.len = f.len + 2; g.pos = r - g.len; g.fail = nodes[f.quick[a]].nxt[a];
      memset(g.nxt, 0, sizeof(g.nxt));
      memcpy(g.quick, nodes[g.fail].quick, sizeof(g.quick));
      g.quick[ts[r - 1 - nodes[g.fail].len] - OFFSET] = g.fail;
      f.nxt[a] = nodesLen++;  // this needs to be after setting g.fail
    }
    if (nodes[suf = f.nxt[a]].len == r - l) pre = suf;
  }
  void undo() {
    const pair<int, int> h = history[--historyLen];
    if (h.first < 0) {
      // pushFront
      if (nodes[pre].len == r - l) suf = nodes[suf].fail;
      pre = ~h.first;
      if (~h.second) {
        --nodesLen;
        nodes[h.second].nxt[ts[l] - OFFSET] = 0;
      }
      ts[l++] = OFFSET - 1;
    } else {
      // pushBack
      if (nodes[suf].len == r - l) pre = nodes[pre].fail;
      suf = h.first;
      if (~h.second) {
        --nodesLen;
        nodes[h.second].nxt[ts[r - 1] - OFFSET] = 0;
      }
      ts[--r] = OFFSET - 1;
    }
  }

  void dfsPrint(ostream &os, int u, const string &branch, int type) const {
    const Node &f = nodes[u];
    os << branch << ((type == 0) ? "" : (type == 1) ? "|-- " : "`-- ");
    if (f.len <= 0) {
      os << "(" << f.len << ")";
    } else {
      for (int i = f.pos; i < f.pos + f.len; ++i) os << ts[i];
    }
    os << " " << u << " " << f.fail;
    // debug here
    os << "\n";
    int a0 = -1;
    for (int a = 0; a < SIZE; ++a) if (f.nxt[a]) a0 = a;
    for (int a = 0; a < SIZE; ++a) if (f.nxt[a]) {
      dfsPrint(os, f.nxt[a],
               branch + ((type == 0) ? "" : (type == 1) ? "|   " : "    "),
               (a == a0) ? 2 : 1);
    }
  }
  friend ostream &operator<<(ostream &os, const Depam &depam) {
    depam.dfsPrint(os, 0, "  ", 0);
    depam.dfsPrint(os, 1, "", 0);
    return os;
  }
};
Depam<char, 26, 'a'> pam(1000005, 1000005);
struct Oper{
	bool dir;
	int pos;
	char c;
}st[2000005];
int q,top;
char str[10],val[10];
int main(){
	scanf("%d",&q);
	int l=1,r=0,cnt0=0;
	int cntop=0;
	for(int i=1;i<=q;i++){
		scanf("%s",str);
		if(str[1]=='u'){
			scanf("%s",val);
			st[++top]={1,++r,val[0]};
			pam.pushBack(val[0]);
		}
		else {
			if(st[top].pos==l){
				if(st[top].dir)r--;
				else l++,cnt0--;assert(cnt0>=0);
				--top;
				pam.undo();
				cout<< pam.nodesLen - 2<<'\n';
				continue;
			}
			int nd=(cnt0&-cnt0);
			if(!nd)nd++;
			vector<Oper> tmp1,tmp2;
			int L=l,R=r;
			while(nd&&top){
				pam.undo();
				if(st[top].dir)r--,tmp2.push_back(st[top]);
				else {
					l++;
					nd--;
					tmp1.push_back(st[top]);
				}
				top--;
			}
			if(tmp1.size()){
				reverse(tmp1.begin(),tmp1.end());
				reverse(tmp2.begin(),tmp2.end());
				for(int i=0;i<tmp2.size();i++){
					cntop++;
					++r,pam.pushBack(tmp2[i].c);
					st[++top]={1,r,tmp2[i].c};
				}
				for(int i=0;i<tmp1.size();i++){
					cntop++;
					--l,pam.pushFront(tmp1[i].c);
					st[++top]={0,l,tmp1[i].c};
				}
			}
			else {
				//cout<<l<<' '<<r<<'\n';
				for(int i=0;i<tmp2.size();i++){
					//cout<<tmp2[i].pos<<'\n';
					cntop++;
					if(tmp2[i].pos==r+1&&l<=r){
						++r,st[++top]={1,r,tmp2[i].c};
						pam.pushBack(tmp2[i].c);
					}
					else {
						//assert(tmp2[i].pos==l-1||l>r);
						if(l>r)l=r=tmp2[i].pos;
						else --l;
						st[++top]={0,l,tmp2[i].c};
						pam.pushFront(tmp2[i].c);
					}
				}
				cnt0=tmp2.size();
			}
			//assert(st[top].pos==L);
			if(st[top].dir)r--;
			else l++,cnt0--;
			--top;assert(cnt0>=0);
			pam.undo();
			assert((l==L+1&&r==R)||l>r);
		}
		cout<< pam.nodesLen - 2<<'\n';
	}
	cerr<<cntop<<'\n';
}