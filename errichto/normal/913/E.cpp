#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

struct cmp {
	bool operator ()(pair<string,int> c, pair<string,int> d) const {
		string a = c.first;
		string b = d.first;
		if(a.length() != b.length()) return a.length() < b.length();
		return a < b;
	}
};

set<pair<string,int>, cmp> E, T, F;

void add(set<pair<string,int>, cmp> & secik, pair<string,int> s) {
	if(s.first.length() <= 30) secik.insert(s);
}

void fix(set<pair<string,int>, cmp> & secik) {
	set<pair<string, int>, cmp> nowy;
	set<int> already;
	for(auto s : secik) if(!already.count(s.second)) {
		already.insert(s.second);
		nowy.insert(s);
	}
	secik = nowy;
		
}

int neg(int x) {
	return ((1 << 8) - 1) ^ x;
}

map<int, string> ans;

bool contains(const set<pair<string,int>, cmp> & secik, string s) {
	for(const auto & pp : secik) if(pp.first == s) return true;
	return false;
}

void init() {
ans[240] = "x";
ans[204] = "y";
ans[170] = "z";
ans[15] = "!x";
ans[51] = "!y";
ans[85] = "!z";
ans[192] = "x&y";
ans[160] = "x&z";
ans[252] = "x|y";
ans[250] = "x|z";
ans[136] = "y&z";
ans[238] = "y|z";
ans[0] = "!x&x";
ans[12] = "!x&y";
ans[10] = "!x&z";
ans[255] = "!x|x";
ans[207] = "!x|y";
ans[175] = "!x|z";
ans[48] = "!y&x";
ans[34] = "!y&z";
ans[243] = "!y|x";
ans[187] = "!y|z";
ans[80] = "!z&x";
ans[68] = "!z&y";
ans[245] = "!z|x";
ans[221] = "!z|y";
ans[3] = "!x&!y";
ans[5] = "!x&!z";
ans[63] = "!x|!y";
ans[95] = "!x|!z";
ans[17] = "!y&!z";
ans[119] = "!y|!z";
ans[128] = "x&y&z";
ans[234] = "x&y|z";
ans[236] = "x&z|y";
ans[248] = "x|y&z";
ans[254] = "x|y|z";
ans[8] = "!x&y&z";
ans[174] = "!x&y|z";
ans[206] = "!x&z|y";
ans[143] = "!x|y&z";
ans[239] = "!x|y|z";
ans[32] = "!y&x&z";
ans[186] = "!y&x|z";
ans[242] = "!y&z|x";
ans[179] = "!y|x&z";
ans[251] = "!y|x|z";
ans[64] = "!z&x&y";
ans[220] = "!z&x|y";
ans[244] = "!z&y|x";
ans[213] = "!z|x&y";
ans[253] = "!z|x|y";
ans[2] = "!x&!y&z";
ans[171] = "!x&!y|z";
ans[4] = "!x&!z&y";
ans[205] = "!x&!z|y";
ans[93] = "!x&y|!z";
ans[59] = "!x&z|!y";
ans[47] = "!x|!y&z";
ans[191] = "!x|!y|z";
ans[79] = "!x|!z&y";
ans[223] = "!x|!z|y";
ans[16] = "!y&!z&x";
ans[241] = "!y&!z|x";
ans[117] = "!y&x|!z";
ans[115] = "!y|!z&x";
ans[247] = "!y|!z|x";
ans[168] = "(x|y)&z";
ans[200] = "(x|z)&y";
ans[224] = "(y|z)&x";
ans[127] = "!(x&y&z)";
ans[42] = "!(x&y)&z";
ans[21] = "!(x&y|z)";
ans[76] = "!(x&z)&y";
ans[19] = "!(x&z|y)";
ans[7] = "!(x|y&z)";
ans[1] = "!(x|y|z)";
ans[112] = "!(y&z)&x";
ans[87] = "!x&!y|!z";
ans[55] = "!x&!z|!y";
ans[14] = "!x&(y|z)";
ans[172] = "!x&y|x&z";
ans[140] = "!x&y|y&z";
ans[202] = "!x&z|x&y";
ans[138] = "!x&z|y&z";
ans[31] = "!x|!y&!z";
ans[50] = "!y&(x|z)";
ans[176] = "!y&x|x&z";
ans[184] = "!y&x|y&z";
ans[226] = "!y&z|x&y";
ans[162] = "!y&z|x&z";
ans[84] = "!z&(x|y)";
ans[208] = "!z&x|x&y";
ans[216] = "!z&x|y&z";
ans[196] = "!z&y|x&y";
ans[228] = "!z&y|x&z";
ans[81] = "!(!x&y|z)";
ans[49] = "!(!x&z|y)";
ans[69] = "!(!y&x|z)";
ans[13] = "!(!y&z|x)";
ans[35] = "!(!z&x|y)";
ans[11] = "!(!z&y|x)";
ans[195] = "!x&!y|x&y";
ans[163] = "!x&!y|x&z";
ans[139] = "!x&!y|y&z";
ans[197] = "!x&!z|x&y";
ans[165] = "!x&!z|x&z";
ans[141] = "!x&!z|y&z";
ans[60] = "!x&y|!y&x";
ans[46] = "!x&y|!y&z";
ans[92] = "!x&y|!z&x";
ans[58] = "!x&z|!y&x";
ans[90] = "!x&z|!z&x";
ans[78] = "!x&z|!z&y";
ans[209] = "!y&!z|x&y";
ans[177] = "!y&!z|x&z";
ans[153] = "!y&!z|y&z";
ans[116] = "!y&x|!z&y";
ans[114] = "!y&z|!z&x";
ans[102] = "!y&z|!z&y";
ans[83] = "!x&!y|!z&x";
ans[71] = "!x&!y|!z&y";
ans[53] = "!x&!z|!y&x";
ans[39] = "!x&!z|!y&z";
ans[29] = "!x&y|!y&!z";
ans[27] = "!x&z|!y&!z";
ans[194] = "!x&!y&z|x&y";
ans[131] = "!x&!y|x&y&z";
ans[235] = "!x&!y|x&y|z";
ans[164] = "!x&!z&y|x&z";
ans[133] = "!x&!z|x&y&z";
ans[237] = "!x&!z|x&z|y";
ans[56] = "!x&y&z|!y&x";
ans[88] = "!x&y&z|!z&x";
ans[44] = "!x&y|!y&x&z";
ans[190] = "!x&y|!y&x|z";
ans[74] = "!x&z|!z&x&y";
ans[222] = "!x&z|!z&x|y";
ans[152] = "!y&!z&x|y&z";
ans[145] = "!y&!z|x&y&z";
ans[249] = "!y&!z|x|y&z";
ans[100] = "!y&x&z|!z&y";
ans[98] = "!y&z|!z&x&y";
ans[246] = "!y&z|!z&y|x";
ans[232] = "(x|y)&z|x&y";
ans[181] = "!(x&y|z)|x&z";
ans[157] = "!(x&y|z)|y&z";
ans[211] = "!(x&z|y)|x&y";
ans[155] = "!(x&z|y)|y&z";
ans[199] = "!(x|y&z)|x&y";
ans[167] = "!(x|y&z)|x&z";
ans[193] = "!(x|y|z)|x&y";
ans[161] = "!(x|y|z)|x&z";
ans[137] = "!(x|y|z)|y&z";
ans[82] = "!x&!y&z|!z&x";
ans[70] = "!x&!y&z|!z&y";
ans[67] = "!x&!y|!z&x&y";
ans[215] = "!x&!y|!z|x&y";
ans[52] = "!x&!z&y|!y&x";
ans[38] = "!x&!z&y|!y&z";
ans[37] = "!x&!z|!y&x&z";
ans[183] = "!x&!z|!y|x&z";
ans[142] = "!x&(y|z)|y&z";
ans[25] = "!x&y&z|!y&!z";
ans[28] = "!x&y|!y&!z&x";
ans[125] = "!x&y|!y&x|!z";
ans[26] = "!x&z|!y&!z&x";
ans[123] = "!x&z|!y|!z&x";
ans[159] = "!x|!y&!z|y&z";
ans[111] = "!x|!y&z|!z&y";
ans[178] = "!y&(x|z)|x&z";
ans[212] = "!z&(x|y)|x&y";
ans[217] = "!(!x&y|z)|y&z";
ans[185] = "!(!x&z|y)|y&z";
ans[229] = "!(!y&x|z)|x&z";
ans[173] = "!(!y&z|x)|x&z";
ans[227] = "!(!z&x|y)|x&y";
ans[203] = "!(!z&y|x)|x&y";
ans[122] = "!(x&y)&z|!z&x";
ans[110] = "!(x&y)&z|!z&y";
ans[124] = "!(x&z)&y|!y&x";
ans[130] = "!x&!y&z|x&y&z";
ans[132] = "!x&!z&y|x&y&z";
ans[62] = "!x&(y|z)|!y&x";
ans[94] = "!x&(y|z)|!z&x";
ans[40] = "!x&y&z|!y&x&z";
ans[72] = "!x&y&z|!z&x&y";
ans[188] = "!x&y|!y&x|x&z";
ans[218] = "!x&z|!z&x|x&y";
ans[144] = "!y&!z&x|x&y&z";
ans[118] = "!y&(x|z)|!z&y";
ans[96] = "!y&x&z|!z&x&y";
ans[230] = "!y&z|!z&y|x&y";
ans[61] = "!(!x&!y&z|x&y)";
ans[20] = "!(!x&!y|x&y|z)";
ans[91] = "!(!x&!z&y|x&z)";
ans[18] = "!(!x&!z|x&z|y)";
ans[65] = "!(!x&y|!y&x|z)";
ans[113] = "!(!x&y|z)|!y&x";
ans[33] = "!(!x&z|!z&x|y)";
ans[103] = "!(!y&!z&x|y&z)";
ans[6] = "!(!y&!z|x|y&z)";
ans[77] = "!(!y&x|z)|!x&y";
ans[9] = "!(!y&z|!z&y|x)";
ans[43] = "!(!z&x|y)|!x&z";
ans[23] = "!((x|y)&z|x&y)";
ans[149] = "!(x&y|z)|x&y&z";
ans[147] = "!(x&z|y)|x&y&z";
ans[135] = "!(x|y&z)|x&y&z";
ans[129] = "!(x|y|z)|x&y&z";
ans[66] = "!x&!y&z|!z&x&y";
ans[219] = "!x&!y|!z&x|y&z";
ans[231] = "!x&!y|!z&y|x&z";
ans[36] = "!x&!z&y|!y&x&z";
ans[189] = "!x&!z|!y&x|y&z";
ans[24] = "!x&y&z|!y&!z&x";
ans[126] = "!x&y|!y&z|!z&x";
ans[106] = "!(x&y)&z|!z&x&y";
ans[108] = "!(x&z)&y|!y&x&z";
ans[120] = "!(y&z)&x|!x&y&z";
ans[89] = "!(!x&y|z)|!x&y&z";
ans[57] = "!(!x&z|y)|!x&y&z";
ans[101] = "!(!y&x|z)|!y&x&z";
ans[45] = "!(!y&z|x)|!y&x&z";
ans[99] = "!(!z&x|y)|!z&x&y";
ans[75] = "!(!z&y|x)|!z&x&y";
ans[169] = "!(x|y|z)|(x|y)&z";
ans[201] = "!(x|y|z)|(x|z)&y";
ans[225] = "!(x|y|z)|(y|z)&x";
ans[86] = "!x&!y&z|!z&(x|y)";
ans[210] = "!x&!y&z|!z&x|x&y";
ans[198] = "!x&!y&z|!z&y|x&y";
ans[54] = "!x&!z&y|!y&(x|z)";
ans[180] = "!x&!z&y|!y&x|x&z";
ans[166] = "!x&!z&y|!y&z|x&z";
ans[30] = "!x&(y|z)|!y&!z&x";
ans[156] = "!x&y|!y&!z&x|y&z";
ans[154] = "!x&z|!y&!z&x|y&z";
ans[148] = "!(!x&!y|x&y|z)|x&y&z";
ans[146] = "!(!x&!z|x&z|y)|x&y&z";
ans[134] = "!(!y&!z|x|y&z)|x&y&z";
ans[151] = "!((x|y)&z|x&y)|x&y&z";
ans[233] = "!(x|y|z)|(x|y)&z|x&y";
ans[214] = "!x&!y&z|!z&(x|y)|x&y";
ans[182] = "!x&!z&y|!y&(x|z)|x&z";
ans[158] = "!x&(y|z)|!y&!z&x|y&z";
ans[104] = "!x&y&z|!y&x&z|!z&x&y";
ans[73] = "!(!x&y|!y&x|z)|!x&y&z";
ans[97] = "!(!x&y|!y&x|z)|!y&x&z";
ans[121] = "!(!x&y|z)|!x&y&z|!y&x";
ans[41] = "!(!x&z|!z&x|y)|!x&y&z";
ans[109] = "!(!y&x|z)|!x&y|!y&x&z";
ans[107] = "!(!z&x|y)|!x&z|!z&x&y";
ans[22] = "!(!x&!y|x&y|z)|!x&!y&z";
ans[150] = "!(!x&!y|x&y|z)|!x&!y&z|x&y&z";
ans[105] = "!(!x&y|!y&x|z)|!x&y&z|!y&x&z";
}

int main() {
	init();
	assert((int) ans.size() == 256);
	int n;
	scanf("%d", &n);
	while(n--) {
		char sl[10];
		scanf("%s", sl);
		int mask = 0;
		for(int i = 0; i < 8; ++i)
			if(sl[i] == '1') mask += 1 << i;
		printf("%s\n", ans[mask].c_str());
	}
	return 0;
	int mask = 0;
	for(int i = 0; i < 8; ++i)
		if(i >= 4) mask |= 1 << i;
	F.insert({"x", mask});
	mask = 0;
	for(int i = 0; i < 8; ++i)
		if((i / 2) % 2)
			mask |= 1 << i;
	F.insert({"y", mask});
	mask = 0;
	for(int i = 0; i < 8; ++i)
		if(i % 2)
			mask |= 1 << i;
	F.insert({"z", mask});
	int row = 0;
	while(true) {
		fix(E);
		fix(T);
		fix(F);
		//~ debug() << "check";
		debug() << imie(contains(E, "x"));
		debug() << imie(contains(T, "y&z"));
		debug() << imie(contains(T, "y")) imie(contains(F, "z"));
		set<pair<string,int>, cmp> E2, T2, F2;
		
		E2 = T;
		for(pair<string,int> a : E) for(pair<string,int> b : T)
			add(E2, {a.first + "|" + b.first, a.second | b.second});
		
		T2 = F;
		for(pair<string,int> a : T) for(pair<string,int> b : F)
			add(T2, {a.first + "&" + b.first, a.second & b.second});
		
		F2 = F;
		for(pair<string,int> a : F) if(a.first[0] != '!')
			add(F2, {"!" + a.first, neg(a.second)});
		for(pair<string,int> a : E) add(F2, {"(" + a.first + ")", a.second});
		
		set<pair<string,int>, cmp> old, nowe;
		for(auto A : {E, T, F})
			for(auto s : A)
				old.insert(s);
		E = E2;
		T = T2;
		F = F2;
		fix(E);
		fix(T);
		fix(F);
		for(auto A : {E, T, F})
			for(auto s : A)
				nowe.insert(s);
		cerr << imie(E.size()) imie(T.size()) imie(F.size()) << "\n";
		if(nowe == old) {
			++row;
			if(row < 5) continue;
			fix(nowe);
			set<int> they;
			for(pair<string,int> s : nowe) {
				cout << "ans[" << s.second << "] = \"" << s.first << "\";\n";
				//~ cout << s.first << " " << s.second << "\n";
				they.insert(s.second);
			}
			cerr << "size = " << they.size() << "\n";
			
			break;
		}
		else row = 0;
	}
}