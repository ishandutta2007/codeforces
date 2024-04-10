#include<cstdio>
#include<map>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int cnt, ans, muchii_componenta_conexa, varfuri_componenta_conexa, Nr_puncte, n, l_p_inter, ap[10009];

double eps = 0.000001, M_PI = acos (-1.0);

map < pair < int, int > , int > cnt_muchii;
vector < int > muchii[10009];

double mod(double x)
{
    if (x<0) return -x;
    return x;
}

bool egal (double a, double b)
{
    return (mod(a-b) <= eps);
}

struct cerc
{
    int xc, yc, R;
}a[209];

class point
{
    public:
    double x, y;
    point ()
    {
        x = y = 0;
    }
    point (double px, double py)
    {
        x = px;
        y = py;
    }
    point sub (point p2)
    {
        return point (x - p2.x, y - p2.y);
    }
    point add (point p2)
    {
        return point (x + p2.x, y + p2.y);
    }
    double distance (point p2)
    {
        return (double)sqrt((double)(x-p2.x) * (x-p2.x) + (y-p2.y) * (y-p2.y));
    }
    point scale (double s)
    {
        x = (double) x * s;
        y = (double) y * s;
        return point(x, y);
    }
    bool operator == (point p2)
    {
        return (egal(x, p2.x) && egal(y, p2.y));
    }
    bool operator < (point p2)
    {
        if (egal (x, p2.x)) return y<p2.y;
        return x<p2.x;
    }
};
point p_inter[10009], toate_punctele[10009];

int get_cod(point P)
{
    for (int i=1; i<=Nr_puncte; i++)
        if (toate_punctele[i] == P) return i;
}

point make_point (double x, double y)
{
    point ans;
    ans.x = x;
    ans.y = y;
    return ans;
}

double dist (point a, point b)
{
    return (double) sqrt ( (double) (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) );
}

bool pe_cerc (cerc a, double x, double y)
{
    return egal ( (double)a.R * a.R,
                 (double)(x - a.xc) * (x - a.xc) + (y - a.yc) * (y - a.yc) );
}

void Intersectie (cerc a, cerc b)
{
    point P0, P1;
    P0 = point (a.xc, a.yc);
    P1 = point (b.xc, b.yc);
    double D, A, H;
    D = dist (P0, P1);
    if (dist (make_point(a.xc, a.yc), make_point (b.xc, b.yc)) > a.R + b.R + eps ) return ;
    if (dist (make_point(a.xc, a.yc), make_point (b.xc, b.yc)) < mod(a.R - b.R ) - eps ) return ;

    A = (double)(a.R * a.R - b.R * b.R + D * D ) / (2 * D);
    H = (double) sqrt ((double) a.R * a.R - A * A);
    point P2 = P1.sub(P0).scale(A/D).add(P0);
    double x3, y3, x4, y4;
    x3 = P2.x + H*(P1.y - P0.y)/D;
    y3 = P2.y - H*(P1.x - P0.x)/D;
    x4 = P2.x - H*(P1.y - P0.y)/D;
    y4 = P2.y + H*(P1.x - P0.x)/D;
    p_inter [++ l_p_inter] = point (x3, y3);
    if (!egal(x3, x4) || !egal(y3, y4)) p_inter [++ l_p_inter] = point (x4, y4);
}

void citesc_cerc(cerc &a)
{
    scanf ("%d %d %d", &a.xc, &a.yc, &a.R);
}

double Det_Unghi(double x, double y)
{
    double result = (double)atan2 (y,x) * 180 / M_PI + 90;
    if (result < 0) result = 360 + result;
    return result;
}

struct unghi_si_provenienta
{
    double unghi;
    int de_unde;
}puncte_intersectie_cerc_curent[409];

bool cmp_unghi_si_provenienta (unghi_si_provenienta a, unghi_si_provenienta b)
{
    return ((double)a.unghi < (double)b.unghi);
}

void Add_Edge (int nod1, int nod2)
{
    if (nod1 < nod2)
    {
        cnt_muchii[make_pair(nod1, nod2)] ++;
        if (cnt_muchii[make_pair(nod1, nod2)] != 1) return ;
    }
    else
    {
        cnt_muchii[make_pair(nod2, nod1)] ++;
        if (cnt_muchii[make_pair(nod2, nod1)] != 1) return ;
    }
    muchii [nod1] . push_back (nod2);
    if (nod1 != nod2) muchii [nod2] . push_back (nod1);
}

void dfs (int nod)
{
    ap[nod] = 1;
    varfuri_componenta_conexa ++;
    for (vector < int > :: iterator it = muchii[nod].begin(); it != muchii[nod].end(); it++)
    {
        if (nod <= *it) muchii_componenta_conexa += cnt_muchii[make_pair (nod, *it)];
        if (ap[*it] == 0) dfs (*it);
    }
}

void Read()
{
    int n_init;
    cerc inutil[209];

    scanf ("%d", &n_init);
    for (int i=1; i<=n_init; i++)
        citesc_cerc (inutil[i]);

    for (int i=1; i<=n_init; i++)
    {
        bool nu = 0;
        for (int j=i+1; j<=n_init; j++)
            if (inutil[i].R == inutil[j].R && inutil[i].xc == inutil[j].xc && inutil[i].yc == inutil[j].yc )
            {
                nu = 1;
                break;
            }
        if (nu == 0)
            a[++n] = inutil[i];
    }
}

void precalculare_pentru_determinarea_codurilor()
{
    for (int i=1; i<=n; i++)
        for (int j=i+1; j<=n; j++)
            Intersectie (a[i], a[j]);
    for (int i=1; i<=l_p_inter; i++)
        for (int j=i+1; j<=l_p_inter; j++)
            if (p_inter[j] < p_inter[i])
            {
                point aux = p_inter[i];
                p_inter[i] = p_inter[j];
                p_inter[j] = aux;
            }
    for (int i=1; i<=l_p_inter; i++)
        if (i==1 || (i>1 && !(p_inter[i-1] == p_inter[i])))
            toate_punctele [++Nr_puncte] = p_inter[i];
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

Read ();

precalculare_pentru_determinarea_codurilor();
for (int i=1; i<=n; i++)
{
    l_p_inter = 0;
    for (int j=1; j<=n; j++)
        if (j != i) Intersectie (a[i], a[j]);

    if (l_p_inter == 0)
    {
        ans ++;
        continue;
    }

    for (int j=1; j<=l_p_inter; j++)
    {
        puncte_intersectie_cerc_curent[j].de_unde = get_cod(p_inter[j]);
        puncte_intersectie_cerc_curent[j].unghi = Det_Unghi (
                                                             (double)p_inter[j].x - a[i].xc,
                                                             (double)p_inter[j].y - a[i].yc);
    }

    sort (puncte_intersectie_cerc_curent + 1, puncte_intersectie_cerc_curent + l_p_inter + 1, cmp_unghi_si_provenienta);
    for (int j=1; j<l_p_inter; j++)
        if (puncte_intersectie_cerc_curent[j].de_unde != puncte_intersectie_cerc_curent[j+1].de_unde)
            Add_Edge(puncte_intersectie_cerc_curent[j].de_unde, puncte_intersectie_cerc_curent[j+1].de_unde);
    Add_Edge(puncte_intersectie_cerc_curent[l_p_inter].de_unde, puncte_intersectie_cerc_curent[1].de_unde);
}
for (int i=1; i<=Nr_puncte; i++)
    if (ap[i] == 0)
    {
        muchii_componenta_conexa = 0;
        varfuri_componenta_conexa = 0;
        dfs (i);
        ans += muchii_componenta_conexa - varfuri_componenta_conexa + 1;
    }
printf ("%d\n", ans + 1);

return 0;
}