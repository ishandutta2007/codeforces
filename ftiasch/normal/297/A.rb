count = gets.scan('1').size
count += 1 if count % 2 == 1
puts count >= gets.scan('1').size ? "YES" : "NO"