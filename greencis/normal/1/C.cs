using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading;

class Program
{
    static void Main(string[] args)
    {
        string[] ta = Console.ReadLine().Replace('.', ',').Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
        double x1 = double.Parse(ta[0]);
        double y1 = double.Parse(ta[1]);
        ta = Console.ReadLine().Replace('.', ',').Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
        double x2 = double.Parse(ta[0]);
        double y2 = double.Parse(ta[1]);
        ta = Console.ReadLine().Replace('.', ',').Split(new char[] { ' ', '\t' }, StringSplitOptions.RemoveEmptyEntries);
        double x3 = double.Parse(ta[0]);
        double y3 = double.Parse(ta[1]);

        if ((x1 - x2) * (y1 + y2) + (x2 - x3) * (y2 + y3) + (x3 - x1) * (y3 + y1) < 0)
        {
            double t = x1;
            x1 = x3;
            x3 = t;
            t = y1;
            y1 = y3;
            y3 = t;
        }

        double xa1 = (x1 + x2) / 2;
        double ya1 = (y1 + y2) / 2;
        double xa2 = xa1 + (ya1 - y1);
        double ya2 = ya1 - (xa1 - x1);
        double A1 = ya1 - ya2;
        double B1 = xa2 - xa1;
        double C1 = -A1 * xa1 - B1 * ya1;

        double xb1 = (x2 + x3) / 2;
        double yb1 = (y2 + y3) / 2;
        double xb2 = xb1 + (yb1 - y2);
        double yb2 = yb1 - (xb1 - x2);
        double A2 = yb1 - yb2;
        double B2 = xb2 - xb1;
        double C2 = -A2 * xb1 - B2 * yb1;

        double xc = -(C1 * B2 - C2 * B1) / (A1 * B2 - A2 * B1);
        double yc = -(A1 * C2 - A2 * C1) / (A1 * B2 - A2 * B1);

        double angle1 = Math.Atan2(y2 - yc, x2 - xc) - Math.Atan2(y1 - yc, x1 - xc);
        while (angle1 < 0) angle1 += 2 * Math.PI;
        while (angle1 >= 2 * Math.PI) angle1 -= 2 * Math.PI;
        double angle2 = Math.Atan2(y3 - yc, x3 - xc) - Math.Atan2(y2 - yc, x2 - xc);
        while (angle2 < 0) angle2 += 2 * Math.PI;
        while (angle2 >= 2 * Math.PI) angle2 -= 2 * Math.PI;
        double angle3 = Math.Atan2(y1 - yc, x1 - xc) - Math.Atan2(y3 - yc, x3 - xc);
        while (angle3 < 0) angle3 += 2 * Math.PI;
        while (angle3 >= 2 * Math.PI) angle3 -= 2 * Math.PI;

        for (int i = 3; i <= 100; ++i)
        {
            int q1 = isInteger(angle1 * i / (2 * Math.PI));
            int q2 = isInteger(angle2 * i / (2 * Math.PI));
            int q3 = isInteger(angle3 * i / (2 * Math.PI));
            double S = ((xc - x1) * (xc - x1) + (yc - y1) * (yc - y1)) * 0.5 * Math.Sin(2 * Math.PI / i) * i;

            if (q1 >= 1 && q2 >= 1 && q3 >= 1 && q1 + q2 + q3 == i)
            {                
                Console.WriteLine(S.ToString().Replace(',', '.'));         
                return;
            }
        }
    }

    static int isInteger(double x)
    {
        bool good = Math.Abs(x - Math.Round(x)) <= 1e-5;
        if (good) return (int)Math.Round(x);
        else return -1;
    }
}