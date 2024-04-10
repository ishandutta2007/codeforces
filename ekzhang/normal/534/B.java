import java.io.*;
import java.util.*;

public class B {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int begin = Integer.parseInt(st.nextToken());
		int end = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		int t = Integer.parseInt(st.nextToken());
		int d = Integer.parseInt(st.nextToken());
		int speed = 0;
		int ans = 0;
		for (int time = 0; time < t; time++) {
			// calc speed
			if (time == 0) {
				speed = begin;
			}
			else {
				int maxSpeed = end + (t - time - 1) * d;
				if (maxSpeed - speed <= d && maxSpeed >= speed) {
					speed = maxSpeed;
				}
				else if (maxSpeed < speed && speed - maxSpeed <= d) {
					speed = maxSpeed;
				}
				else if (maxSpeed > speed) {
					speed += d;
				}
				else {
					throw new IllegalArgumentException();
				}
			}
			ans += speed;
		}
		out.println(ans);
		out.flush();
		System.exit(0);
	}

}