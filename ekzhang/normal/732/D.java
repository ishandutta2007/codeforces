/**
 * Created by ezhang on 7/23/17.
 */
import java.util.*;
import java.io.*;

public class CF_732D {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[] D = new int[N];
        int[] A = new int[M];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++)
            D[i] = Integer.parseInt(st.nextToken()) - 1;

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < M; i++)
            A[i] = Integer.parseInt(st.nextToken());

        int lo = 1;
        int hi = N + 1;
        while (lo != hi) {
            int mid = (lo + hi) / 2;
            // see if using first mid days [0..mid) is sufficient
            boolean[] seen = new boolean[M];
            int debt = 0;
            int count = 0;
            for (int i = mid - 1; i >= 0; i--) {
                if (D[i] != -1 && !seen[D[i]]) {
                    seen[D[i]] = true;
                    ++count;
                    debt -= A[D[i]];
                }
                else {
                    if (debt < 0) ++debt;
                }
            }

            if (debt == 0 && count == M) {
                // we can take all the tests in the first mid days
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        out.println(lo <= N ? lo : -1);

        out.flush();
        System.exit(0);
    }
}