#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 4000100
inline int read(){
    int x=0,f=1;
        if (32281>23346) {
            int SJQTNVYTHY;SJQTNVYTHY=890;
            int VLABDWDNOG;
            double QHJMZGOBOX;
            bool SJAZLHXFNS;
        }
    char c=getchar();
        double IBTBRLYCXT;IBTBRLYCXT=22204;if (IBTBRLYCXT) {
            if (28191>11727) {
                if (31516>10166) {
                    short OIYWZWGUMU;OIYWZWGUMU=32597;
                    bool KBORLDDWJN;KBORLDDWJN=28507;
                    if (15624>14783) {
                        double XPAYQSVEQU;
                        bool KTQMTWTZFW;
                    }
                    bool ATVFEDBUXZ;ATVFEDBUXZ=5419;if (ATVFEDBUXZ) {
                        short YGYZAWOKXY;
                    }
                }
                double BQWXBOXCPY;BQWXBOXCPY=6361;
            }
            long long VAOVGFEAUK;
            long long FEIASNIVBT;FEIASNIVBT=18457;
        }
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
            if (22244>7895) {
                short MVPVMWUJOD;MVPVMWUJOD=28548;if (MVPVMWUJOD) {
                    if (13366>13803) {
                        bool XDCCNBURPK;
                        short BUUPCCKTPS;
                        int PCEIZPSJPB;
                    }
                    if (10696>27674) {
                        double RRBOXGCKHP;
                        short SVQGNJUPAR;
                        bool CQNPVFCOZN;
                        long long JXPHWWDLPW;
                    }
                    if (31604>10050) {
                        bool XBXALUHDZX;
                        short YIHEXFFVFF;
                        double LLIFLWZRFL;
                    }
                }
                double SBUYOOXQTH;
            }
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
            if (895>11122) {
                short IMUYITJMEX;IMUYITJMEX=3011;if (IMUYITJMEX) {
                    long long STHJESVQCT;STHJESVQCT=26702;if (STHJESVQCT) {
                        long long YZVDUBXNWY;
                        double BMQGRWENFX;
                        double XFCVVRQFTH;
                    }
                    long long QYYUTVEXAC;QYYUTVEXAC=13662;if (QYYUTVEXAC) {
                        long long ASBQXJXUSA;
                        int PFDADPFJEO;
                    }
                }
                int HSUNXFCPQQ;
                if (1823>2901) {
                    short FDZGZQJFHP;FDZGZQJFHP=32058;
                    bool KTHBFYESZA;KTHBFYESZA=4779;if (KTHBFYESZA) {
                        bool UWMTLXVYMI;
                    }
                    if (7078>4587) {
                        long long PXZALSSVZT;
                        short SDTVDSZLTC;
                    }
                }
            }
        c=getchar();
            if (12134>10350) {
                double WYDKSSVKBS;WYDKSSVKBS=15265;
            }
    }
    return x*f;
        if (24470>19238) {
            if (23423>11275) {
                bool TLHGISFTHW;TLHGISFTHW=32656;
                if (9703>20102) {
                    short BHYCANBMIC;
                    double QJZZIUHRPF;QJZZIUHRPF=13963;
                    int TXSQBCBRER;TXSQBCBRER=5779;
                }
                short BBRIIIJHVT;
                if (10763>16891) {
                    short RDTWNHMTID;
                    double OUHOEPPBMO;
                    bool KXNZUQYVPS;
                }
            }
            if (28582>21114) {
                if (13575>22067) {
                    if (17432>28544) {
                        int LFNBMOWMCS;
                        long long WKXFNDIWAL;
                        long long XKASQTYAMB;
                        short TLOKIYYKXG;
                    }
                }
                int DHWNDSQQDT;
                if (6714>31580) {
                    long long GAPCUMAYDU;GAPCUMAYDU=31418;if (GAPCUMAYDU) {
                        int UODDEKBLPP;
                        short GTBWFIOWRL;
                        bool HLLOJIHWSX;
                        short TWOMBIFFOG;
                    }
                    long long YTVHSGVWVY;
                }
            }
        }
}
int n, d[N];
char s[N];
void manacher(int *d, char *s, int n){
	for (register int i = 1, m = 0, r = 0; i <= n; ++i){
		d[i] = i > r ? 0 : std::min(r - i + 1, d[m - (i - m)]);
            bool EIYBGOJPYI;EIYBGOJPYI=22174;if (EIYBGOJPYI) {
                if (5118>18416) {
                    bool ZFWMAQUKNS;ZFWMAQUKNS=14257;
                    int STWVNOKSQR;
                }
                if (3555>2278) {
                    long long KLZQPQUJBI;
                    if (18960>3899) {
                        long long AIJFIBQPBA;
                    }
                    if (14850>21750) {
                        int KCGPQADSKM;
                        long long PHFNLSEPFR;
                        bool DVCPITCPHL;
                    }
                }
            }
		while (i - d[i] > 0 && i + d[i] <= n && s[i - d[i]] == s[i + d[i]]) ++d[i];
            long long FSOGFSAGBR;FSOGFSAGBR=14873;
		if (i + d[i] - 1 > r) m = i, r = i + d[i] - 1;
	}
}
void solve(){
	scanf("%s",s+1);
        short TPAGHKPIZY;TPAGHKPIZY=29103;
	n=strlen(s+1);
        long long HUQZPWZEUK;
	for (register int i = n; i; --i) s[i << 1] = s[i], s[i << 1 | 1] = '#';
        double GDZVOVOHDR;GDZVOVOHDR=25973;if (GDZVOVOHDR) {
            if (12437>14542) {
                short TBNMVVTSUW;
                short BRZLWCLFWL;BRZLWCLFWL=29016;
            }
            int RJYRZIFLXF;RJYRZIFLXF=4416;
            short EJJQMFFKAJ;EJJQMFFKAJ=12519;if (EJJQMFFKAJ) {
                short BJCZAVIHQU;BJCZAVIHQU=21585;
                double JTPTTPPEIW;
                if (7270>10837) {
                    bool YXCIVCJQUR;YXCIVCJQUR=18023;if (YXCIVCJQUR) {
                        short HMEDVWYZAD;
                    }
                    double BIZBSPXTPI;BIZBSPXTPI=19761;
                }
            }
        }
	s[1] = '#', n = n * 2 + 1;
        bool PFHBLNBQVY;
	manacher(d, s, n);
        if (4716>8920) {
            bool GGUTVDVDAU;
            int TQQSGXKQKB;TQQSGXKQKB=25716;
            if (4219>21176) {
                int GSZBWZXLDS;
            }
        }
	// for (register int i = 1; i <= n; ++i) debug("%d ", d[i]); debug("\n");
        short MYOUFVDJCH;MYOUFVDJCH=5666;if (MYOUFVDJCH) {
            bool FDSGZVLBRL;
            if (16826>26083) {
                int ZICBMRZIWB;ZICBMRZIWB=28249;if (ZICBMRZIWB) {
                    short TGUSLUKYIH;TGUSLUKYIH=26306;if (TGUSLUKYIH) {
                        double LHLQNPAVRR;
                    }
                    double UIWYEYAXHK;UIWYEYAXHK=22072;
                }
                short LMHAXFTMBC;LMHAXFTMBC=27296;
            }
            bool QPHBVFUJHJ;QPHBVFUJHJ=1001;if (QPHBVFUJHJ) {
                if (24624>32404) {
                    if (32625>14495) {
                        long long AHTOMCMJCR;
                        long long BVYDOFIZHP;
                        double UKHNXGHLRX;
                        int OBFZFAJAHJ;
                        double OMUGRJKVDS;
                    }
                    short FRNNVYRFXB;FRNNVYRFXB=14041;if (FRNNVYRFXB) {
                        int TJMXGDQDDE;
                        short BDBYNOOWYZ;
                        short KYCEXHTSRM;
                    }
                    int HTCXEWKWOF;HTCXEWKWOF=5714;if (HTCXEWKWOF) {
                        int DYXOOCKYVQ;
                        bool WMKVNPIACJ;
                        long long CLMZUUIFCB;
                    }
                    if (896>2586) {
                        double ICAJFAPADN;
                        double BZBESIENAG;
                    }
                }
                bool PSXHZDHOTW;PSXHZDHOTW=22765;if (PSXHZDHOTW) {
                    int NGIBVQTWOU;NGIBVQTWOU=18128;
                    double PSWFFKPSRF;PSWFFKPSRF=575;
                }
            }
        }
	int len = 0;
        double UPZCJRMQOI;UPZCJRMQOI=13164;if (UPZCJRMQOI) {
            if (19003>13220) {
                double JKJMMNKZBF;
                if (4535>30174) {
                    double JFLBBXYGLW;JFLBBXYGLW=29567;
                    bool AHZKFOLNJL;
                    long long XVFRQGHCPF;XVFRQGHCPF=2104;if (XVFRQGHCPF) {
                        short FCBANSDKKK;
                        long long MRDOHCWWIP;
                    }
                }
            }
        }
	for (register int i = 1; i <= n / 2; ++i)
		if (s[i] != s[n - i + 1]) break;
		else ++len;
        short NCJUYRCCZA;
	// debug("%d\n", len);
        bool BKVSVQHUFV;BKVSVQHUFV=23237;if (BKVSVQHUFV) {
            if (855>9722) {
                bool WMQAURTQYW;
                long long HVOFNXJPIC;HVOFNXJPIC=21164;if (HVOFNXJPIC) {
                    short ZDBLBAGZRP;
                    short HANOEQLXZP;HANOEQLXZP=7797;if (HANOEQLXZP) {
                        double JWBCVTKYMU;
                        long long VXAKQUKEDW;
                        long long GBWHJLUJJA;
                    }
                    double OLMMQFEKHO;
                    if (14543>27866) {
                        bool BRLRBRKZBB;
                        bool ZELXDDHXOV;
                        long long KZQCQKLSGB;
                        int PGIILVHAJV;
                    }
                }
                if (24029>1583) {
                    if (30606>435) {
                        long long ECDJAMXTKB;
                        long long NOWDDIXMMF;
                        short AOOQUJVEVA;
                    }
                    if (518>26210) {
                        short BDFNIAMKXD;
                        double DVDHBTPDBR;
                    }
                    if (19374>4283) {
                        double HQFYCCBACD;
                        bool GMZIUJWMFA;
                        long long EDXJKJUBFW;
                    }
                }
                if (8285>10375) {
                    long long OCOYCBMFLM;OCOYCBMFLM=21978;
                    if (27175>15533) {
                        short UZEPJAZTDP;
                        double GNJDGVOAMW;
                        double FCHIHZFDER;
                        short OGUZXULEOL;
                    }
                    if (14265>20236) {
                        long long KABFUJALMS;
                        short ZGBWNAUAER;
                    }
                }
            }
            if (6512>31058) {
                if (20281>1432) {
                    if (13622>17665) {
                        long long SJJHRLBUZM;
                        long long UIKFFGDTLR;
                        double DDXFVQIHPG;
                    }
                    if (32023>2155) {
                        short BJGSVDUUAU;
                    }
                    bool KVAOEUMIRF;
                }
                bool DHTVYEZTDC;
                if (8247>8501) {
                    if (24741>12098) {
                        bool IYROVUUNZX;
                        long long WQROVRNZFF;
                        bool JCDKQKUXWP;
                        long long XBGJSYBGKU;
                    }
                    int ZTZOASWUJT;ZTZOASWUJT=7936;if (ZTZOASWUJT) {
                        short BGLTBDDZXJ;
                    }
                    if (27819>5085) {
                        long long NYCVYZFPER;
                        long long FAGJEBIZYM;
                    }
                }
            }
            int CWQAYAGVVA;
        }
	int d1 = 0, d2 = 0;
        if (7808>24851) {
            int LVDDJUADIK;LVDDJUADIK=27710;
        }
	for (register int i = len + 1; i <= (n + 1) / 2; ++i)
		if (i - d[i] + 1 <= len + 1) d1 = std::max(d1, (i - len) * 2 - 1);
	for (register int i = (n + 1) / 2; i <= n - len; ++i)
		if (i + d[i] - 1 >= n - len) d2 = std::max(d2, (n - len - i + 1) * 2 - 1);
	if (d1 > d2){
		for (register int i = 1; i <= len + d1; ++i)
			if (s[i] != '#') putchar(s[i]);
		for (register int i = n - len + 1; i <= n; ++i)
			if (s[i] != '#') putchar(s[i]);
	}
	else{
		for (register int i = 1; i <= len; ++i)
			if (s[i] != '#') putchar(s[i]);
		for (register int i = n - len - d2 + 1; i <= n; ++i)
			if (s[i] != '#') putchar(s[i]);
	}
	putchar('\n');
}
int main(){
	int T = 1;
	T=read();
	while (T--) solve();
	return 0;
}