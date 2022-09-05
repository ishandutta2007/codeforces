#include<bits/stdc++.h>

using namespace std;

int x[10], y[10], z[20], l[3][256], fin[3][256];
const int inf = 10000;
string dp[3][256];

void U (int i, int j, string s)
{
    if ((s.length () < l[i][j]) || (s.length () == l[i][j] && s < dp[i][j]))
    {
        dp[i][j] = s, l[i][j] = s.length ();
        assert (fin[i][j] == 0);
        /*if (fin[i][j] == 1)
        {
            fprintf (stderr, "%s\n", s.c_str ());
            x[9] = 0;
        }*/
    }
}

void preprocess ()
{
    dp[0][0]="!x&x";
dp[0][1]="!(x|y|z)";
dp[0][2]="!x&!y&z";
dp[0][3]="!x&!y";
dp[0][4]="!x&!z&y";
dp[0][5]="!x&!z";
dp[0][6]="!(!y&!z|x|y&z)";
dp[0][7]="!(x|y&z)";
dp[0][8]="!x&y&z";
dp[0][9]="!(!y&z|!z&y|x)";
dp[0][10]="!x&z";
dp[0][11]="!(!z&y|x)";
dp[0][12]="!x&y";
dp[0][13]="!(!y&z|x)";
dp[0][14]="!x&(y|z)";
dp[0][15]="!x";
dp[0][16]="!y&!z&x";
dp[0][17]="!y&!z";
dp[0][18]="!(!x&!z|x&z|y)";
dp[0][19]="!(x&z|y)";
dp[0][20]="!(!x&!y|x&y|z)";
dp[0][21]="!(x&y|z)";
dp[0][22]="!(!x&!y|x&y|z)|!x&!y&z";
dp[0][23]="!((x|y)&z|x&y)";
dp[0][24]="!x&y&z|!y&!z&x";
dp[0][25]="!x&y&z|!y&!z";
dp[0][26]="!x&z|!y&!z&x";
dp[0][27]="!x&z|!y&!z";
dp[0][28]="!x&y|!y&!z&x";
dp[0][29]="!x&y|!y&!z";
dp[0][30]="!x&(y|z)|!y&!z&x";
dp[0][31]="!x|!y&!z";
dp[0][32]="!y&x&z";
dp[0][33]="!(!x&z|!z&x|y)";
dp[0][34]="!y&z";
dp[0][35]="!(!z&x|y)";
dp[0][36]="!x&!z&y|!y&x&z";
dp[0][37]="!x&!z|!y&x&z";
dp[0][38]="!x&!z&y|!y&z";
dp[0][39]="!x&!z|!y&z";
dp[0][40]="!x&y&z|!y&x&z";
dp[0][41]="!(!x&z|!z&x|y)|!x&y&z";
dp[0][42]="!(x&y)&z";
dp[0][43]="!(!z&x|y)|!x&z";
dp[0][44]="!x&y|!y&x&z";
dp[0][45]="!(!y&z|x)|!y&x&z";
dp[0][46]="!x&y|!y&z";
dp[0][47]="!x|!y&z";
dp[0][48]="!y&x";
dp[0][49]="!(!x&z|y)";
dp[0][50]="!y&(x|z)";
dp[0][51]="!y";
dp[0][52]="!x&!z&y|!y&x";
dp[0][53]="!x&!z|!y&x";
dp[0][54]="!x&!z&y|!y&(x|z)";
dp[0][55]="!x&!z|!y";
dp[0][56]="!x&y&z|!y&x";
dp[0][57]="!(!x&z|y)|!x&y&z";
dp[0][58]="!x&z|!y&x";
dp[0][59]="!x&z|!y";
dp[0][60]="!x&y|!y&x";
dp[0][61]="!(!x&!y&z|x&y)";
dp[0][62]="!x&(y|z)|!y&x";
dp[0][63]="!x|!y";
dp[0][64]="!z&x&y";
dp[0][65]="!(!x&y|!y&x|z)";
dp[0][66]="!x&!y&z|!z&x&y";
dp[0][67]="!x&!y|!z&x&y";
dp[0][68]="!z&y";
dp[0][69]="!(!y&x|z)";
dp[0][70]="!x&!y&z|!z&y";
dp[0][71]="!x&!y|!z&y";
dp[0][72]="!x&y&z|!z&x&y";
dp[0][73]="!(!x&y|!y&x|z)|!x&y&z";
dp[0][74]="!x&z|!z&x&y";
dp[0][75]="!(!z&y|x)|!z&x&y";
dp[0][76]="!(x&z)&y";
dp[0][77]="!(!y&x|z)|!x&y";
dp[0][78]="!x&z|!z&y";
dp[0][79]="!x|!z&y";
dp[0][80]="!z&x";
dp[0][81]="!(!x&y|z)";
dp[0][82]="!x&!y&z|!z&x";
dp[0][83]="!x&!y|!z&x";
dp[0][84]="!z&(x|y)";
dp[0][85]="!z";
dp[0][86]="!x&!y&z|!z&(x|y)";
dp[0][87]="!x&!y|!z";
dp[0][88]="!x&y&z|!z&x";
dp[0][89]="!(!x&y|z)|!x&y&z";
dp[0][90]="!x&z|!z&x";
dp[0][91]="!(!x&!z&y|x&z)";
dp[0][92]="!x&y|!z&x";
dp[0][93]="!x&y|!z";
dp[0][94]="!x&(y|z)|!z&x";
dp[0][95]="!x|!z";
dp[0][96]="!y&x&z|!z&x&y";
dp[0][97]="!(!x&y|!y&x|z)|!y&x&z";
dp[0][98]="!y&z|!z&x&y";
dp[0][99]="!(!z&x|y)|!z&x&y";
dp[0][100]="!y&x&z|!z&y";
dp[0][101]="!(!y&x|z)|!y&x&z";
dp[0][102]="!y&z|!z&y";
dp[0][103]="!(!y&!z&x|y&z)";
dp[0][104]="!x&y&z|!y&x&z|!z&x&y";
dp[0][105]="!(!x&y|!y&x|z)|!x&y&z|!y&x&z";
dp[0][106]="!(x&y)&z|!z&x&y";
dp[0][107]="!(!z&x|y)|!x&z|!z&x&y";
dp[0][108]="!(x&z)&y|!y&x&z";
dp[0][109]="!(!y&x|z)|!x&y|!y&x&z";
dp[0][110]="!(x&y)&z|!z&y";
dp[0][111]="!x|!y&z|!z&y";
dp[0][112]="!(y&z)&x";
dp[0][113]="!(!x&y|z)|!y&x";
dp[0][114]="!y&z|!z&x";
dp[0][115]="!y|!z&x";
dp[0][116]="!y&x|!z&y";
dp[0][117]="!y&x|!z";
dp[0][118]="!y&(x|z)|!z&y";
dp[0][119]="!y|!z";
dp[0][120]="!(y&z)&x|!x&y&z";
dp[0][121]="!(!x&y|z)|!x&y&z|!y&x";
dp[0][122]="!(x&y)&z|!z&x";
dp[0][123]="!x&z|!y|!z&x";
dp[0][124]="!(x&z)&y|!y&x";
dp[0][125]="!x&y|!y&x|!z";
dp[0][126]="!x&y|!y&z|!z&x";
dp[0][127]="!(x&y&z)";
dp[0][128]="x&y&z";
dp[0][129]="!(x|y|z)|x&y&z";
dp[0][130]="!x&!y&z|x&y&z";
dp[0][131]="!x&!y|x&y&z";
dp[0][132]="!x&!z&y|x&y&z";
dp[0][133]="!x&!z|x&y&z";
dp[0][134]="!(!y&!z|x|y&z)|x&y&z";
dp[0][135]="!(x|y&z)|x&y&z";
dp[0][136]="y&z";
dp[0][137]="!(x|y|z)|y&z";
dp[0][138]="!x&z|y&z";
dp[0][139]="!x&!y|y&z";
dp[0][140]="!x&y|y&z";
dp[0][141]="!x&!z|y&z";
dp[0][142]="!x&(y|z)|y&z";
dp[0][143]="!x|y&z";
dp[0][144]="!y&!z&x|x&y&z";
dp[0][145]="!y&!z|x&y&z";
dp[0][146]="!(!x&!z|x&z|y)|x&y&z";
dp[0][147]="!(x&z|y)|x&y&z";
dp[0][148]="!(!x&!y|x&y|z)|x&y&z";
dp[0][149]="!(x&y|z)|x&y&z";
dp[0][150]="!(!x&!y|x&y|z)|!x&!y&z|x&y&z";
dp[0][151]="!((x|y)&z|x&y)|x&y&z";
dp[0][152]="!y&!z&x|y&z";
dp[0][153]="!y&!z|y&z";
dp[0][154]="!x&z|!y&!z&x|y&z";
dp[0][155]="!(x&z|y)|y&z";
dp[0][156]="!x&y|!y&!z&x|y&z";
dp[0][157]="!(x&y|z)|y&z";
dp[0][158]="!x&(y|z)|!y&!z&x|y&z";
dp[0][159]="!x|!y&!z|y&z";
dp[0][160]="x&z";
dp[0][161]="!(x|y|z)|x&z";
dp[0][162]="!y&z|x&z";
dp[0][163]="!x&!y|x&z";
dp[0][164]="!x&!z&y|x&z";
dp[0][165]="!x&!z|x&z";
dp[0][166]="!x&!z&y|!y&z|x&z";
dp[0][167]="!(x|y&z)|x&z";
dp[0][168]="(x|y)&z";
dp[0][169]="!(x|y|z)|(x|y)&z";
dp[0][170]="z";
dp[0][171]="!x&!y|z";
dp[0][172]="!x&y|x&z";
dp[0][173]="!(!y&z|x)|x&z";
dp[0][174]="!x&y|z";
dp[0][175]="!x|z";
dp[0][176]="!y&x|x&z";
dp[0][177]="!y&!z|x&z";
dp[0][178]="!y&(x|z)|x&z";
dp[0][179]="!y|x&z";
dp[0][180]="!x&!z&y|!y&x|x&z";
dp[0][181]="!(x&y|z)|x&z";
dp[0][182]="!x&!z&y|!y&(x|z)|x&z";
dp[0][183]="!x&!z|!y|x&z";
dp[0][184]="!y&x|y&z";
dp[0][185]="!(!x&z|y)|y&z";
dp[0][186]="!y&x|z";
dp[0][187]="!y|z";
dp[0][188]="!x&y|!y&x|x&z";
dp[0][189]="!x&!z|!y&x|y&z";
dp[0][190]="!x&y|!y&x|z";
dp[0][191]="!x|!y|z";
dp[0][192]="x&y";
dp[0][193]="!(x|y|z)|x&y";
dp[0][194]="!x&!y&z|x&y";
dp[0][195]="!x&!y|x&y";
dp[0][196]="!z&y|x&y";
dp[0][197]="!x&!z|x&y";
dp[0][198]="!x&!y&z|!z&y|x&y";
dp[0][199]="!(x|y&z)|x&y";
dp[0][200]="(x|z)&y";
dp[0][201]="!(x|y|z)|(x|z)&y";
dp[0][202]="!x&z|x&y";
dp[0][203]="!(!z&y|x)|x&y";
dp[0][204]="y";
dp[0][205]="!x&!z|y";
dp[0][206]="!x&z|y";
dp[0][207]="!x|y";
dp[0][208]="!z&x|x&y";
dp[0][209]="!y&!z|x&y";
dp[0][210]="!x&!y&z|!z&x|x&y";
dp[0][211]="!(x&z|y)|x&y";
dp[0][212]="!z&(x|y)|x&y";
dp[0][213]="!z|x&y";
dp[0][214]="!x&!y&z|!z&(x|y)|x&y";
dp[0][215]="!x&!y|!z|x&y";
dp[0][216]="!z&x|y&z";
dp[0][217]="!(!x&y|z)|y&z";
dp[0][218]="!x&z|!z&x|x&y";
dp[0][219]="!x&!y|!z&x|y&z";
dp[0][220]="!z&x|y";
dp[0][221]="!z|y";
dp[0][222]="!x&z|!z&x|y";
dp[0][223]="!x|!z|y";
dp[0][224]="(y|z)&x";
dp[0][225]="!(x|y|z)|(y|z)&x";
dp[0][226]="!y&z|x&y";
dp[0][227]="!(!z&x|y)|x&y";
dp[0][228]="!z&y|x&z";
dp[0][229]="!(!y&x|z)|x&z";
dp[0][230]="!y&z|!z&y|x&y";
dp[0][231]="!x&!y|!z&y|x&z";
dp[0][232]="(x|y)&z|x&y";
dp[0][233]="!(x|y|z)|(x|y)&z|x&y";
dp[0][234]="x&y|z";
dp[0][235]="!x&!y|x&y|z";
dp[0][236]="x&z|y";
dp[0][237]="!x&!z|x&z|y";
dp[0][238]="y|z";
dp[0][239]="!x|y|z";
dp[0][240]="x";
dp[0][241]="!y&!z|x";
dp[0][242]="!y&z|x";
dp[0][243]="!y|x";
dp[0][244]="!z&y|x";
dp[0][245]="!z|x";
dp[0][246]="!y&z|!z&y|x";
dp[0][247]="!y|!z|x";
dp[0][248]="x|y&z";
dp[0][249]="!y&!z|x|y&z";
dp[0][250]="x|z";
dp[0][251]="!y|x|z";
dp[0][252]="x|y";
dp[0][253]="!z|x|y";
dp[0][254]="x|y|z";
dp[0][255]="!x|x";
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

/*
E ::= E '|' T | T

T ::= T '&' F | F

F ::= '!' F | '(' E ')' | 'x' | 'y' | 'z'
*/
preprocess ();
/*for (int msk = 0; msk < 8; msk ++)
    x[msk] = msk / 4, y[msk] = (msk / 2) % 2, z[msk] = msk % 2;
for (int i=0; i<3; i++)
    for (int j=0; j<256; j++)
        l[i][j] = inf;
for (int j=0; j<3; j++)
{
    int msk = 0;
    for (int k=0; k<8; k++)
    {
        bool ok = 0;
        if (x[k] == 1 && j == 0) ok = 1;
        else
        if (y[k] == 1 && j == 1) ok = 1;
        else
        if (z[k] == 1 && j == 2) ok = 1;
        if (ok) msk |= 1 << k;
    }
    dp[2][msk].push_back ('x' + j), l[2][msk] = 1, fin[2][msk] = 1;
}
int fixed = 0;

char gh = 34;
//printf ("%c\n", gh);
while (1)
{
    for (int i=0; i<256; i++)
    {
        if (l[1][i] < inf) U (0, i, dp[1][i]);
        if (l[2][i] < inf) U (1, i, dp[2][i]);
        if (l[2][i] < inf) U (2, i ^ 255, "!" + dp[2][i]);
        if (l[0][i] < inf) U (2, i, "(" + dp[0][i] + ")");
    }
    for (int t=0; t<256; t++)
        for (int f=0; f<256; f++)
            if (l[1][t] < inf && l[2][f] < inf)
                U (1, t & f, dp[1][t] + "&" + dp[2][f]);
    for (int e=0; e<256; e++)
        for (int t=0; t<256; t++)
            if (l[0][e] < inf && l[1][t] < inf)
                U (0, e | t, dp[0][e] + "|" + dp[1][t]);
    int pi = -1, pj = -1, mini = inf;
    for (int i=0; i<3; i++)
        for (int j=0; j<256; j++)
            if (l[i][j] < mini && fin[i][j] != 1)
                mini = l[i][j], pi = i, pj = j;
    if (mini == inf) break;
    fin[pi][pj] = 1;
    fprintf (stderr, "%d fixed\n", ++fixed);
}
for (int i=0; i<256; i++)
    printf ("dp[0][%d]=%c%s%c;\n", i, gh, dp[0][i].c_str (), gh);*/
int Tests;
scanf ("%d", &Tests);
while (Tests --)
{
    char sir[20];
    scanf ("%s", sir);
    int msk = 0;
    for (int i=0; i<8; i++)
        if (sir[i] == '1')
            msk |= 1 << i;
    printf ("%s\n", dp[0][msk].c_str ());
}
return 0;
}